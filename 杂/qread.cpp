// kririae
struct IO {
char ibuf[1 << 18], *s, *t, obuf[1 << 18], *o, vbuf[65];
IO() : s(ibuf), t(ibuf), o(obuf) {}
~IO() { fwrite(obuf, 1, o - obuf, stdout); }
inline char gc() {
  (s == t) && 
  (t = (s = ibuf) + fread(ibuf, 1, 1 << 18, stdin));
  return s == t ? 0 : *s++;
}
inline void pc(char c) {
  (o == obuf + (1 << 18)) &&
  (fwrite(obuf, 1, 1 << 18, stdout), o = obuf);
  *o++ = c;
}
template<typename T>
operator T() {
  register T r = 0, f = 1; 
  register char c = gc();
  for (; !isdigit(c); c = gc())
    f = c == '-' ? -1 : 1;
  for (; isdigit(c); c = gc())
    r = (((r << 2) + r) << 1) + (c - '0');
  return f == 1 ? r : -r;
}
void operator = (char x) { pc(x); }
void operator = (const char *x) {
  register int u = 0;
  while(x[u]) pc(x[u++]);
}
template<typename T>
void operator = (T x) {
  register int u = 0;
  if(x == 0) return pc('0'), void();
  if(x < 0) x = -x, pc('-');
  while(x) vbuf[++u] = x % 10 + 48, x /= 10;
  while(u) pc(vbuf[u--]);
}
} io;

// lpa20020220
template<typename T>
inline void read(T &val)
{
  val = 0; char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) val = (val << 1) + (val << 3) + c - 48, c = getchar();
}

// Margatroid
namespace IO
{
inline char gc()
{
  static char buf[1 << 18], *fs, *ft;
  return (fs == ft && (ft = (fs = buf) + fread(buf, 1, 1 << 18, stdin)), fs == ft) ? EOF : *fs++;
}
inline int read()
{
  register int k = 0, f = 1;
  register char c = gc();
  for (; !isdigit(c); c = gc()) if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) k = (k << 3) + (k << 1) + (c - '0');
  return k * f;
}
}

// xehoth pre
namespace IO
{
inline char gc()
{
  static char buf[1 << 18];
  static int s = 0, t = 0;
  s == t ? s = 0, t = fread(buf, 1, 1 << 18, stdin) : 0;
  return s == t ? -1 : buf[s++];
}
template<class T>
inline void read(T &val)
{
  int m, c;
  for (m = 1, c = gc(); !isdigit(c); c = gc()) m = c == '-' ? -1 : 1;
  if(c == -1) return;
  for (val = 0; isdigit(c); c = gc()) val = (val << 3) + (val << 1) + (c - '0');
  val = m == -1 ? -val : val;
}
}

template<class T>
struct IO
{
char buf[1 << 18], *s, *t;
IO() : s(), t() {}
inline char gc() {
  s == t && t = (s = buf) + 
  fread(buf, 1, 1 << 18, stdin);
  return s == t ? 0 : *s++;
}
operator T() {
  T ret = 0, T f = 1, char c = gc()
  for (; !isdigit(c); c = gc()) 
    f = c == '-' ? -1 : 1;
  for (; isdigit(c); c = gc()) 
    ret = (((ret << 2) + ret) << 1) + (c - '0');
  return f == 1 ? ret : -ret;
}
}
// HigHwind
template<class T>
struct IO
{
char p[1 << 20], *s, e[1 << 20], *t;
T a[65];
IO() : s(p), t(e) { fread(s, 1, sizeof p, stdin); }
~IO() { fwrite(e, 1, t - e, stdout); }
operator T() 
{
  static T v, j;
  v = 0, j = 1;
  while (*s < 48) j = *s++ ^ 45;
  do v = (((v << 2) + v) << 1) + *s++ - 48; 
  while (*s > 32);
  return j ? v : -v;
}
void print(T v) 
{
  static T *q = a;
  if (!v) *t++ = 48;
  else {
  if (v < 0) *t++ = 45, v *= -1;
  while (v) *q++ = v % 10 + 48, v /= 10;
  while (q != a) *t++ = *--q;
  } *t++ = '\n';
}
};

/*
IO<int> in;
a = in;
with problems
 */

// xehoth curr
struct InputOutputStream 
{
enum { SIZE = 1024 * 1024 };
char ibuf[SIZE], *s, *t, obuf[SIZE], *oh;
InputOutputStream() : s(), t(), oh(obuf) {}
~InputOutputStream() { fwrite(obuf, 1, oh - obuf, stdout); }
inline char read() {
  if (s == t) t = (s = ibuf) + fread(ibuf, 1, SIZE, stdin);
  return s == t ? -1 : *s++;
}
template <typename T>
inline InputOutputStream &operator>>(T &x) {
  static char c;
  static bool iosig;
  for (c = read(), iosig = false; !isdigit(c); c = read()) {
    if (c == -1) return *this;
    iosig |= c == '-';
  }
  for (x = 0; isdigit(c); c = read()) x = x * 10 + (c ^ '0');
  if (iosig) x = -x;
  return *this;
}
inline void print(char c) {
  if (oh == obuf + SIZE) {
    fwrite(obuf, 1, SIZE, stdout);
    oh = obuf;
  }
  *oh++ = c;
}
template <typename T>
inline void print(T x) {
  static int buf[21], cnt;
  if (x != 0) {
    if (x < 0) {
      print('-');
      x = -x;
    }
    for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 | 48;
    while (cnt) print((char)buf[cnt--]);
  } else {
    print('0');
  }
}
template <typename T>
inline InputOutputStream &operator<<(const T &x) {
  print(x);
  return *this;
}
} io;