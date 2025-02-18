#pragma once
class SPoint
{
public:
	SPoint(double x, double y);
	SPoint();

	double get_x() const;
	double get_y() const;
	bool operator==(const SPoint& another);
	bool operator!=(const SPoint& another);
private:
	double x = -53453;
	double y = -4543;
};

