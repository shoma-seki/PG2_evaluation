#include "Shake.h"

void Shake::Initialize(){

}

void Shake::Update(bool isShake){
	if (isShake == true) {
		random_.vector2[0] = float(rand() % 7 - 4);
		random_.vector2[1] = float(rand() % 7 - 4);
	}
}
