#ifndef INTERVAL_H

#define INTERVAL_H
class Interval {
	float min;  // valoarea minima a intervalului
	float max;  // valoarea maxima a intervalului
	friend class Semnal;
public:
	void setInterval(float, float);
};
#endif

