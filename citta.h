#ifdef DENSE

#define SO_WIDTH 20
#define SO_HEIGHT 10
#define SO_HOLES 10
#define SO_TOP_CELLS 40
#define SO_CAP_MIN 1
#define SO_CAP_MAX 1
#define SO_TIMENSEC_MIN 100000000
#define SO_TIMENSEC_MAX 300000000
#define SO_TIMEOUT 1
#define SO_DURATION 20
#endif

#ifdef LARGE
#define SO_WIDTH 60
#define SO_HEIGHT 20
#define SO_HOLES 50
#define SO_TOP_CELLS 40
#define SO_SOURCES 10;
#define SO_CAP_MIN 3
#define SO_CAP_MAX 5
#define SO_TAXY 1000
#define SO_TIMENSEC_MIN 10000000
#define SO_TIMENSEC_MAX 100000000
#define SO_TIMEOUT 3
#define SO_DURATION 20
#endif

void createCity();
void genCouples();
void editCouples(int i, int * r, int * c);
int rand();