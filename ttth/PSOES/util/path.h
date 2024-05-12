
struct path {
    double distance, angle;
    point *begin;
    path() : distance(1000000), angle(1000000), begin(nullptr) {}
    path(point *p1) : distance(1000000), angle(1000000), begin(p1) {}
    path(double distance1, double angle1, point *p1) : distance(distance1), angle(angle1), begin(p1) {}
};

point relative;

double distanceToFinish(double x, double y) {
    point *p = new point(x, y, nullptr);
    return euclideanDistance(p, finish);
}

bool checkValidPosition(point *p){
    int x = p->x, y = p->y;
    if(x < 0 || y < 0 || x > mapHeight || y > mapWidth) return false;
    if(graphStatus[x][y] != 0 || graphStatus[x+1][y] != 0 || graphStatus[x][y+1] != 0 || graphStatus[x+1][y+1] != 0) return false;
    return true;
}

bool checkValidPosition(double x1, double y1){
    int x = x1, y = y1;
    if(x < 0 || y < 0 || x > mapHeight || y > mapWidth) return false;
    if(graphStatus[x][y] != 0 || graphStatus[x+1][y] != 0 || graphStatus[x][y+1] != 0 || graphStatus[x+1][y+1] != 0) return false;
    return true;
}

bool checkValidPoint(point *p){
    int x = p->x, y = p->y;
    if(x < 0 || y < 0 || x > mapHeight || y > mapWidth) return false;
    if(graphStatus[x][y] != 0) return false;
    return true;
}

bool checkValidPoint(int x, int y){
    if(x < 0 || y < 0 || x > mapHeight || y > mapWidth) return false;
    if(graphStatus[x][y] != 0) return false;
    return true;
}

double angleVector(point *p1, point *p2){
    return atan(p2->y - p1->y / p2->x - p1->x);
}

double compareTwoPath(path *a, path *b) {
    // return b->angle - a->angle + b->distance - a->distance;
    return 2 * (b->angle - a->angle) / b->angle + (b->distance - a->distance) / b->distance;
}

// int compareTwoPath(path *a, path *b) {
//     // return a->angle < b->angle + a->distance < b->distance;
//     return a->distance < b->distance;
// }

void pathFunc(path *path){
    // cout << "cc";
    point *p = path->begin, *p1 = p->next;
    double x = p1->x - p->x, y = p1->y - p->y;
    double z = sqrt(x*x + y*y);
    double distance = z, angle = 0, pastAngle = acos(x/z) * (y >= 0 ? 1 : -1), currAngle;
    while(p->next != nullptr){
        p1 = p->next;
        x = p1->x - p->x;
        y = p1->y - p->y;
        z = sqrt(x*x + y*y);
        distance += z;
        currAngle = 100 * acos(x/z) * (y >= 0 ? 1 : -1);
        angle += pow(currAngle - pastAngle, 2);
        pastAngle = currAngle;
        p = p1;
        // cout << angle << " ";
    }
    path->distance = distance;
    path->angle = angle;
}

void pathFunc1(path *path){
    cout << endl;
    point *p = path->begin, *p1 = p->next;
    double x = p1->x - p->x, y = p1->y - p->y;
    double z = sqrt(x*x + y*y);
    double distance = z, angle = 0, pastAngle = acos(x/z) * (y >= 0 ? 1 : -1), currAngle;
    while(p->next != nullptr){
        p1 = p->next;
        x = p1->x - p->x;
        y = p1->y - p->y;
        z = sqrt(x*x + y*y);
        distance += z;
        currAngle = 10 * acos(x/z) * (y >= 0 ? 1 : -1);
        cout << currAngle << " " << (x/z) << endl;
        angle += pow(currAngle - pastAngle, 2);
        pastAngle = currAngle;
        p = p1;
        // cout << angle << " ";
    }
    path->distance = distance;
    path->angle = angle;
}

