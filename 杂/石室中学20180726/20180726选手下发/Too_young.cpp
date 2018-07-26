void spawning(int P,int Q,int R,int S,int Mod){
	int T=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			T=(T+(1ll*(i+j)*P+1ll*i*j*Q+1ll*i*R+1ll*j*S)%Mod+Mod)%Mod;
			A[i][j]=T;
		}
	A[P%n+1][P%m+1]^=1;A[P%n+1][Q%m+1]^=1;A[P%n+1][R%m+1]^=1;A[P%n+1][S%m+1]^=1;
	A[Q%n+1][P%m+1]^=1;A[Q%n+1][Q%m+1]^=1;A[Q%n+1][R%m+1]^=1;A[Q%n+1][S%m+1]^=1;
	A[R%n+1][P%m+1]^=1;A[R%n+1][Q%m+1]^=1;A[R%n+1][R%m+1]^=1;A[R%n+1][S%m+1]^=1;
	A[S%n+1][P%m+1]^=1;A[S%n+1][Q%m+1]^=1;A[S%n+1][R%m+1]^=1;A[S%n+1][S%m+1]^=1;
}


void checker(){
	long long Pin=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			Pin+=(1ll*i*n+j)*A[i][j];
		}
	}printf("%lld\n",Pin);
}

