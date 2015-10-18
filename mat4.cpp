#include "vec3.h"
#include "mat4.h"

#define PI 3.14159265359

	// ** 2A: **

Mat4::Mat4( )
{
	SetIdentity( );
}


Mat4::Mat4(	float a, float b, float c, float d, float e, float f, float g, float h,
		float i, float j, float k, float l, float n, float o, float p, float q )
{
	m[0][0]	= a;	m[0][1]	= b;	m[0][2]	= c;	m[0][3]	= d;
	m[1][0]	= e;	m[1][1]	= f;	m[1][2]	= g;	m[1][3]	= h;
	m[2][0]	= i;	m[2][1]	= j;	m[2][2]	= k;	m[2][3]	= l;
	m[3][0]	= n;	m[3][1]	= o;	m[3][2]	= p;	m[3][3]	= q;
}

Mat4&
Mat4::operator=( const Mat4& that )
{
	// "this" is a pointer to this class's mat4  (this->name)
	// "that" is a reference to the other matrix (that.name)

	for ( int i = 0; i < 4; ++i )
	{
		for ( int j = 0; j < 4; ++j )
		{
				this->m[i][j] = that.m[i][j];				 
		}	
	} 
	return *this;
}

Mat4
Mat4::operator*( Mat4& that )
{
	// "this" is a pointer to this class's mat4  (this->name)
	// "that" is a reference to the other matrix (that.name)

	Mat4 result;
	for ( int i = 0; i < 4; ++i )
	{
		for ( int j = 0; j < 4; ++j )
		{
				result.m[i][j] = this->m[i][0] * that.m[0][j] + 
								 this->m[i][1] * that.m[1][j] + 
								 this->m[i][2] * that.m[2][j] + 
								 this->m[i][3] * that.m[3][j] ; 
		}	
	}   
	return result;
}

Vec3
Mat4::operator*( Vec3& that )
{
	// "this" is a pointer to this class's mat4  (this->name)
	// "that" is a reference to the vector (that.name)

	Vec3 result;
	result = Vec3( this->m[0][0] * that.x + this->m[1][0] * that.x + this->m[2][0] * that.x + this->m[3][0] * that.x ,
				   this->m[0][1] * that.y + this->m[1][1] * that.y + this->m[2][1] * that.y + this->m[3][1] * that.y ,
				   this->m[0][2] * that.z + this->m[1][2] * that.z + this->m[2][2] * that.z + this->m[3][2] * that.z );
	return result;
}

void
Mat4::Print( char *str, FILE *fp )
{
	// "this" is a pointer to this class's mat4  (this->name)

	fprintf( fp, "%s \n", str );
	fprintf( fp, "\t%8.2f  %8.2f  %8.2f  %8.2f\n", this->m[0][0], this->m[0][1], this->m[0][2], this->m[0][3] );
	fprintf( fp, "\t%8.2f  %8.2f  %8.2f  %8.2f\n", this->m[1][0], this->m[1][1], this->m[1][2], this->m[1][3] );
	fprintf( fp, "\t%8.2f  %8.2f  %8.2f  %8.2f\n", this->m[2][0], this->m[2][1], this->m[2][2], this->m[2][3] );
	fprintf( fp, "\t%8.2f  %8.2f  %8.2f  %8.2f\n", this->m[3][0], this->m[3][1], this->m[3][2], this->m[3][3] );
}

void
Mat4::SetIdentity( )
{
	this->m[0][0]	= 1;	this->m[0][1]	= 0;	this->m[0][2]	= 0;	this->m[0][3]	= 0;
	this->m[1][0]	= 0;	this->m[1][1]	= 1;	this->m[1][2]	= 0;	this->m[1][3]	= 0;
	this->m[2][0]	= 0;	this->m[2][1]	= 0;	this->m[2][2]	= 1;	this->m[2][3]	= 0;
	this->m[3][0]	= 0;	this->m[3][1]	= 0;	this->m[3][2]	= 0;	this->m[3][3]	= 1;
}

	// ** 2B: **

double
sind( double x )
{
	return sin( x * PI / 180 );
}

double
cosd( double x )
{
	return cos( x * PI / 180 );
}

void
Mat4::SetRotateX( float d )
{
	this->m[0][0]	= 1;	this->m[0][1]	= 0;	this->m[0][2]	= 0;	this->m[0][3]	= 0;
	this->m[1][0]	= 0;	this->m[1][1]= cosd(d);	this->m[1][2]=-sind(d);	this->m[1][3]	= 0;
	this->m[2][0]	= 0;	this->m[2][1]= sind(d);	this->m[2][2]= cosd(d);	this->m[2][3]	= 0;
	this->m[3][0]	= 0;	this->m[3][1]	= 0;	this->m[3][2]	= 0;	this->m[3][3]	= 1;
}

void
Mat4::SetRotateY( float d )
{
	this->m[0][0]= cosd(d);	this->m[0][1]	= 0;	this->m[0][2]= sind(d);	this->m[0][3]	= 0;
	this->m[1][0]	= 0;	this->m[1][1]	= 1;	this->m[1][2]	= 0;	this->m[1][3]	= 0;
	this->m[2][0]=-sind(d);	this->m[2][1]	= 0;	this->m[2][2]= cosd(d);	this->m[2][3]	= 0;
	this->m[3][0]	= 0;	this->m[3][1]	= 0;	this->m[3][2]	= 0;	this->m[3][3]	= 1;
}

void
Mat4::SetRotateZ( float d )
{
	this->m[0][0]= cosd(d);	this->m[0][1]=-sind(d);	this->m[0][2]	= 0;	this->m[0][3]	= 0;
	this->m[1][0]= sind(d);	this->m[1][1]= cosd(d);	this->m[1][2]	= 0;	this->m[1][3]	= 0;
	this->m[2][0]	= 0;	this->m[2][1]	= 0;	this->m[2][2]	= 1;	this->m[2][3]	= 0;
	this->m[3][0]	= 0;	this->m[3][1]	= 0;	this->m[3][2]	= 0;	this->m[3][3]	= 1;
}



void
Mat4::SetScale( float sx, float sy, float sz )
{
	this->m[0][0]	= sx;	this->m[0][1]	= 0;	this->m[0][2]	= 0;	this->m[0][3]	= 0;
	this->m[1][0]	= 0;	this->m[1][1]	= sy;	this->m[1][2]	= 0;	this->m[1][3]	= 0;
	this->m[2][0]	= 0;	this->m[2][1]	= 0;	this->m[2][2]	= sz;	this->m[2][3]	= 0;
	this->m[3][0]	= 0;	this->m[3][1]	= 0;	this->m[3][2]	= 0;	this->m[3][3]	= 1;
}

void
Mat4::SetTranslate( float tx, float ty, float tz )
{
	this->m[0][0]	= 1;	this->m[0][1]	= 0;	this->m[0][2]	= 0;	this->m[0][3]	= tx;
	this->m[1][0]	= 0;	this->m[1][1]	= 1;	this->m[1][2]	= 0;	this->m[1][3]	= ty;
	this->m[2][0]	= 0;	this->m[2][1]	= 0;	this->m[2][2]	= 1;	this->m[2][3]	= tz;
	this->m[3][0]	= 0;	this->m[3][1]	= 0;	this->m[3][2]	= 0;	this->m[3][3]	= 1;
}