#pragma once
#include "Eigen\Dense"

using namespace Eigen;
using namespace std;

extern MatrixXd get4x4TransformMatrix(MatrixXd Rot, Vector3d Pos);
extern MatrixXd getRotationMatrix(Vector3d rot);
extern MatrixXd getEulerMatrix(Vector3d rot);
extern Vector3d getRotationAngle(MatrixXd rotation_matrix);
extern Vector3d getEulerAngle(MatrixXd rotation_matrix);
extern Vector3d euler2rot(Vector3d orientation);
extern Vector3d rot2euler(Vector3d orientation);