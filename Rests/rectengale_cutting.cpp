for(int i=0; i<a; i++)
{
    val=min(val,ye(a-i,b)+ye(i,b)+1);
}
for(int i=0; i<b; i++)
{
    val=min(val,ye(a,b-i)+ye(a,i)+1);
}
