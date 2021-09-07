//dien tich cac hinh

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Area {
public:
	virtual double area() = 0;	
};

class Triangle : public Area {
private:
	double a;
	double b;
	double c;
public:
	Triangle() {}
	Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
	double area() {
		double p = (a + b + c) / 2.0;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}

	static double getTriangleMax(vector<Triangle> vt) {
		double max1 = vt[0].area();
		for (int i = 1; i < vt.size(); i++) {
			if (vt[i].area() > max1) {
				max1 = vt[i].area();
			}
		}
		return max1;
	}
};

class Rectangle : public Area {
private:
	double w;
	double h;
public:
	Rectangle(double w, double h) : w(w), h(h) {}
	double area() {
		return w * h;
	}
	
	static double getRectangleMax(vector<Rectangle> vt) {
		double max2 = vt[0].area();
		for (int i = 1; i < vt.size(); i++) {
			if (vt[i].area() > max2) {
				max2 = vt[i].area();
			}
		}
		return max2;
	}
};

class Circle : public Area {
private:
	double r;
public:
	Circle() {}
	Circle(double r) : r(r) {}
	double area() {
		return 3.14 * r * r;
	}
	
	static double getCircleMax(vector<Circle> vt) {
		double max3 = vt[0].area();
		for (int i = 1; i < vt.size(); i++) {
			if (vt[i].area() > max3) {
				max3 = vt[i].area();
			}
		}
		return max3;
	}
};

void fillVectorTriangle(vector<Triangle>&);
void fillVectorRectangle(vector<Rectangle>&);
void fillVectorCircle(vector<Circle>&);

int main() {
	
	vector<Triangle> t;
	vector<Rectangle> r;
	vector<Circle> c;
	fillVectorTriangle(t);
	fillVectorRectangle(r);
	fillVectorCircle(c);
	double x = Triangle::getTriangleMax(t);
	double y = Rectangle::getRectangleMax(r);
	double z = Circle::getCircleMax(c);
	double max = x;
	if (max < y) max = y;
	if (max < z) max = z;
	if (max == x) cout << "Hinh co dien tich lon nhat la hinh tam giac S = " << max << endl;
	else if (max == y) cout << "Hinh co dien tich lon nhat la hinh chu nhat S = " << max << endl;
		else cout << "Hinh co dien tich lon nhat la hinh tron S = " << max << endl;
}


void fillVectorTriangle(vector<Triangle>& triangle) {
	double a, b, c;

	cout << "Nhap so luong hinh tam giac: ";
	int n1;
	cin >> n1;

	for (int i = 0; i < n1; i++) {
		cout << "-----Hinh tam giac thu " << i + 1 << "-----" << endl;
		cout << "Nhap canh thu 1 cua tam giac: ";
		cin >> a;
		cout << "Nhap canh thu 2 cua tam giac: ";
		cin >> b;
		cout << "Nhap canh thu 3 cua tam giac: ";
		cin >> c;

		Triangle newTriangle(a, b, c);
		triangle.push_back(newTriangle);
		cout << endl;
	}
	cout << endl;
}

void fillVectorRectangle(vector<Rectangle>& rectangle) {
	double w, h;

	cout << "Nhap so luong hinh chu nhat: ";
	int n2;
	cin >> n2;

	for (int i = 0; i < n2; i++) {
		cout << "---------Hinh chu nhat thu " << i + 1 << "--------" << endl;
		cout << "Nhap chieu dai hinh chu nhat: ";
		cin >> h;
		cout << "Nhap chieu rong hinh chu nhat: ";
		cin >> w;
		
		Rectangle newRectangle(w, h);
		rectangle.push_back(newRectangle);
		cout << endl;
	}
	cout << endl;
}

void fillVectorCircle(vector<Circle>& circle) {
	double r;

	cout << "Nhap so luong hinh tron: ";
	int n3;
	cin >> n3;

	for (int i = 0; i < n3; i++) {
		cout << "-----Hinh tron thu " << i + 1 << "------" << endl;
		cout << "Nhap ban kinh hinh tron: ";
		cin >> r;
		
		Circle newCircle(r);
		circle.push_back(newCircle);
		cout << endl;
	}
	cout << endl;
}
