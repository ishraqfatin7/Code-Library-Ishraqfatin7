inline bool isLeft(Point a, Point b, Point c)
{
return ((b.x - a.x)*(c.y - a.y) - (b.y      - a.y)*(c.x - a.x)) > 0;
}