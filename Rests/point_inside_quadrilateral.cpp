struct Point {
    double x, y;
};
bool isPointInsideTriangle(Point A, Point B, Point C, Point P) {
    double areaABC = abs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
    double areaPBC = abs((B.x - P.x) * (C.y - P.y) - (C.x - P.x) * (B.y - P.y));
    double areaPCA = abs((C.x - P.x) * (A.y - P.y) - (A.x - P.x) * (C.y - P.y));
    double areaPAB = abs((A.x - P.x) * (B.y - P.y) - (B.x - P.x) * (A.y - P.y));
    return areaPBC + areaPCA + areaPAB == areaABC;
}
bool isPointInsideQuadrilateral(Point A, Point B, Point C, Point D, Point P) {
    return isPointInsideTriangle(A, B, C, P)
        || isPointInsideTriangle(A, B, D, P)
        || isPointInsideTriangle(A, C, D, P)
        || isPointInsideTriangle(B, C, D, P);
}
