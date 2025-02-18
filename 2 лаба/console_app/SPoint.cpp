#include "SPoint.h"


SPoint::SPoint(double x, double y) {
	this->x = x;
	this->y = y;
}

SPoint::SPoint() {
}

double SPoint::get_x() const {
	return this->x;
}

double SPoint::get_y() const {
	return this->y;
}

bool SPoint::operator==(const SPoint& another) {
	if (this->get_x() == another.get_x() and this->get_y() == another.get_y())
		return true;
	return false;
}

bool SPoint::operator!=(const SPoint& another) {
	if (this->get_x() != another.get_x() or (this->get_y() != another.get_y())) {
		return true;
	}
	return false;
}



