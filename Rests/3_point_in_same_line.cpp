
bool check(const pll& a, const pll& b, const pll& c)
{
   return (b.ff-a.ff)*(c.ss-a.ss) - (b.ss-a.ss)*(c.ff-a.ff) == 0;
}