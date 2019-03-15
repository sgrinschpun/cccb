#ifndef _PhenomenaParams
#define _PhenomenaParams
#include <string>
using namespace std;

struct PhenomenaParams{
    int id;
    int parent;
    string name;
    float mass;
    float charge;
    string type;
    float energy;
    float vx;
    float vy;
    float vz;
    float beta;

    bool equals(PhenomenaParams p) {
        return id == p.id;
    }
};
#endif
