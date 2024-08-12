
#include "mesh.h"

class TrivialModel {
public:
    TrivialModel();
    void draw();
private:
    std::vector<Mesh*> meshes;
};
