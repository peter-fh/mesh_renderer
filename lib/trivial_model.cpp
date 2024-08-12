#include "trivial_model.h"

TrivialModel::TrivialModel(){
	this->meshes.push_back(new Mesh);
};

void TrivialModel::draw(){
	for (unsigned int i=0; i < meshes.size(); ++i){
		meshes[i]->draw();
	}
}
