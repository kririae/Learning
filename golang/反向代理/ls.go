package main

import (
	"crypto"
	"crypto/md5"
	"crypto/rand"
	"crypto/rsa"
	"crypto/x509"
	"encoding/hex"
	"encoding/pem"
	"flag"
	"log"
	"net/http"
	"os"
	"strconv"
	"strings"
)

func main() {
	log.SetOutput(os.Stdout)

	address := flag.String("addr", "127.0.0.1:9418", "Bind TCP Address")
	flag.Parse()

	log.Println("Starting server at http://" + *address)
	log.Println("Quit the server with CTRL-C.")

	if strings.Contains(*address, "0.0.0.0") {
		*address = strings.Replace(*address, "0.0.0.0", "", 1)
	}

	routerBinding()
	err := http.ListenAndServe(*address, http.DefaultServeMux)
	if err != nil {
		log.Fatalln(err)
	}
}

func urlMatcher(h http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		r.URL.Path = strings.ToLower(r.URL.Path)
		h.ServeHTTP(w, r)
	})
}

func routerBinding() {
	mux := http.NewServeMux()
	http.Handle("/", urlMatcher(mux))

	mux.HandleFunc("/", index)

	mux.HandleFunc("/rpc/ping.action", ping)

	mux.HandleFunc("/rpc/obtainticket.action", obtainTicket)
}

func index(w http.ResponseWriter, r *http.Request) {
	w.Write([]byte("Server is starting!"))
}

func ping(w http.ResponseWriter, r *http.Request) {
	log.Println(r.URL)
	salt := r.URL.Query().Get("salt")
	xmlResponse := "<PingResponse><message></message><responseCode>OK</responseCode><salt>" + salt + "</salt></PingResponse>"
	xmlSignature, _ := signature(xmlResponse)
	w.Header().Add("Content-Type", "text/xml")
	w.Write([]byte("<!-- " + xmlSignature + " -->\n" + xmlResponse))
}

func obtainTicket(w http.ResponseWriter, r *http.Request) {
	log.Println(r.URL)
	//buildDate := r.URL.Query().Get("buildDate")
	//clientVersion := r.URL.Query().Get("clientVersion")
	//hostName := r.URL.Query().Get("hostName")
	//machineId := r.URL.Query().Get("machineId")
	//productCode := r.URL.Query().Get("productCode")
	//productFamilyId := r.URL.Query().Get("productFamilyId")
	salt := r.URL.Query().Get("salt")
	//secure := r.URL.Query().Get("secure")
	username := r.URL.Query().Get("userName")
	//version := r.URL.Query().Get("version")
	//versionNumber := r.URL.Query().Get("versionNumber")

	if salt == "" || username == "" {
		w.WriteHeader(http.StatusForbidden)
		return
	}

	prolongationPeriod := 607875500

	xmlResponse := "<ObtainTicketResponse><message></message><prolongationPeriod>" + strconv.Itoa(prolongationPeriod) + "</prolongationPeriod><responseCode>OK</responseCode><salt>" + salt + "</salt><ticketId>1</ticketId><ticketProperties>licensee=" + username + "\tlicenseType=0\t</ticketProperties></ObtainTicketResponse>"
	xmlSignature, _ := signature(xmlResponse)
	w.Header().Add("Content-Type", "text/xml")
	w.Write([]byte("<!-- " + xmlSignature + " -->\n" + xmlResponse))
}

var privateKey = []byte(`
-----BEGIN RSA PRIVATE KEY-----
MIIBOgIBAAJBALecq3BwAI4YJZwhJ+snnDFj3lF3DMqNPorV6y5ZKXCiCMqj8OeOmxk4YZW9aaV9
ckl/zlAOI0mpB3pDT+Xlj2sCAwEAAQJAW6/aVD05qbsZHMvZuS2Aa5FpNNj0BDlf38hOtkhDzz/h
kYb+EBYLLvldhgsD0OvRNy8yhz7EjaUqLCB0juIN4QIhAOeCQp+NXxfBmfdG/S+XbRUAdv8iHBl+
F6O2wr5fA2jzAiEAywlDfGIl6acnakPrmJE0IL8qvuO3FtsHBrpkUuOnXakCIQCqdr+XvADI/UTh
TuQepuErFayJMBSAsNe3NFsw0cUxAQIgGA5n7ZPfdBi3BdM4VeJWb87WrLlkVxPqeDSbcGrCyMkC
IFSs5JyXvFTreWt7IQjDssrKDRIPmALdNjvfETwlNJyY
-----END RSA PRIVATE KEY-----
`)

func signature(message string) (string, error) {
	pem, _ := pem.Decode(privateKey)
	rsaPrivateKey, err := x509.ParsePKCS1PrivateKey(pem.Bytes)

	hashedMessage := md5.Sum([]byte(message))
	signature, err := rsa.SignPKCS1v15(rand.Reader, rsaPrivateKey, crypto.MD5, hashedMessage[:])
	if err != nil {
		return "", err
	}
	hexSignature := hex.EncodeToString(signature)
	return hexSignature, nil
}