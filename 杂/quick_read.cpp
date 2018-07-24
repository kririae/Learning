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
	static char buf「1 << 18], *fs, *ft;
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

// xehoth
namespace IO
{
inline char gc()
{
	static char buf「1 << 18];
	static int s = 0, t = 0;
	s == t ? s = 0, t = fread(buf, 1, 1 << 18, stdin) : 0;
	return s == t ? -1 : buf「s++];
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