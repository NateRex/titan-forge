#include <geometry/Vector3.h>
#include <geometry/Vector2.h>
#include <geometry/Utils.h>
#include <math.h>

Vector3::Vector3() : x(0.), y(0.), z(0.)
{

}

Vector3::Vector3(const double x, const double y, const double z) : x(x), y(y), z(z)
{

}

Vector3::Vector3(const Vector2& other) : x(other.x), y(other.y), z(0.)
{

}

Vector3::Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z)
{

}

bool Vector3::isZero(const double tol) const
{
	return equals(x, 0., tol) && equals(y, 0., tol) && equals(z, 0., tol);
}

bool Vector3::equalTo(const Vector3& other, const double tol) const
{
	return equals(x, other.x, tol) && equals(y, other.y, tol) && equals(z, other.z, tol);
}

double Vector3::getMagnitude() const
{
	return sqrt(x * x + y * y + z * z);
}

double Vector3::dot(const Vector3& other) const
{
	return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::cross(const Vector3& other, Vector3* result) const
{
	Vector3 r = getOrDefault(result, Vector3());

	r.x = y * other.z - other.y * z;
	r.y = z * other.x - other.z * x;
	r.z = x * other.y - other.x * y;

	return r;
}

Vector3 Vector3::normalize(Vector3* result) const
{
    double mag = getMagnitude();

    Vector3 r = getOrDefault(result, Vector3());
    if (isZero())
    {
        r.x = 0;
        r.y = 0;
        r.z = 0;
    }
    else
    {
        r.x = x / mag;
        r.y = y / mag;
        r.z = z / mag;
    }

    return r;
}

Vector3 Vector3::scale(const double value, Vector3* result) const
{
    Vector3 res = getOrDefault(result, Vector3());
    res.x = x * value;
    res.y = y * value;
    res.z = z * value;
    return res;
}

Vector3 Vector3::minus(const Vector3& other, Vector3* result) const
{
    Vector3 res = getOrDefault(result, Vector3());
    res.x = x - other.x;
    res.y = y - other.y;
    res.z = z - other.z;
    return res;
}

bool Vector3::operator==(const Vector3& other) const
{
    return equalTo(other, 0.);
}