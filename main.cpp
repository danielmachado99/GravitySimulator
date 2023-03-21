#include <iostream>
#include <vector>
#include <math.h>
#include "draw.h"
using namespace std;

// Driver Code

class object
{
private:
    float mass = 0;
    float velocity_x = 0;
    float velocity_y = 0;
    float x_position = 0;
    float y_position = 0;

public:
    object(vector<object> &objects, float mass, float velocity_x = 0,
           float velocity_y = 0,
           float x_position = 0,
           float y_position = 0)
    {
        (*this).mass = mass;
        (*this).velocity_x = velocity_x;
        (*this).velocity_y = velocity_y;
        (*this).x_position = x_position;
        (*this).y_position = y_position;
        objects.push_back(*this);
        cout << (objects.back()).mass << endl;
        //   this->mass=mass;
    }

    float getmass()
    {
        return ((*this).mass);
    }
    float get_x_position()
    {
        return ((*this).x_position);
    }
    float get_y_position()
    {
        return ((*this).y_position);
    }

    void set_x_position(float timestep)
    {
        (*this).x_position = (*this).x_position + (*this).velocity_x * timestep;
        return;
    }
    void set_y_position(float timestep)
    {
        (*this).y_position = (*this).y_position + (*this).velocity_y * timestep;
        return;
    }
    void set_x_velocity(float velocity_x)
    {
        (*this).velocity_x += velocity_x;
        return;
    }
    void set_y_velocity(float velocity_y)
    {
        (*this).velocity_y += velocity_y;
        return;
    }

    float get_x_velocity()
    {
        return ((*this).velocity_x);
    }
    float get_y_velocity()
    {
        return ((*this).velocity_y);
    }

    //~object();
};

// object::object(/* args */)
// {
// }

// object::~object()
// {
// }

void calculateUpdateVelocity(vector<object> &objects, float timestep)
{
    float g = 6.6743 * pow(10, -11);
    for (size_t i = 0; i < objects.size(); i++)
    {
        for (size_t j = 0; j < objects.size(); j++)
        {
            if (j != i)
            {

                float distancemagnitude = pow(objects.at(i).get_x_position() - objects.at(j).get_x_position(), 2);
                distancemagnitude = distancemagnitude + pow(objects.at(i).get_y_position() - objects.at(j).get_y_position(), 2);
                distancemagnitude = abs(sqrt(distancemagnitude));

                float force = g * (objects.at(j)).getmass() * (objects.at(i)).getmass();

                force = force / pow(distancemagnitude, 2);

                float x_vector = objects.at(i).get_x_position() - objects.at(j).get_x_position();

                x_vector = -x_vector / distancemagnitude;
                // cout << "Force:" << force << "N  | " << endl;
                //  x_vector = abs(x_vector);
                cout << "x_vector:" << x_vector << "N  | " << endl;
                float y_vector = objects.at(i).get_y_position() - objects.at(j).get_y_position();
                y_vector = -y_vector / distancemagnitude;
                // y_vector = abs(y_vector);

                float acceleration = force / objects.at(i).getmass();
                // cout << acceleration * timestep * x_vector << "   " << acceleration * timestep * y_vector << endl;
                objects.at(i).set_x_velocity(acceleration * timestep * x_vector);
                objects.at(i).set_y_velocity(acceleration * timestep * y_vector);
            }
        }
    }
}

void calcualteUpdatePosition(vector<object> &objects, Draw example, float timestep, int j)
{

    for (size_t i = 0; i < objects.size(); i++)
    {
        objects.at(i).set_x_position(timestep);
        objects.at(i).set_y_position(timestep);
        cout << "Object:" << i << "| Position:" << objects.at(i).get_x_position() << ", " << objects.at(i).get_y_position() << "| Velocity:" << objects.at(i).get_x_velocity() << "ms, " << objects.at(i).get_y_velocity() << endl;

        // cout << i << " vel- " << objects.at(i).get_x_velocity() << "ms, " << objects.at(i).get_y_velocity() << endl;
        example.SetRenderDrawColor(255, 255, 255, 255);
        example.RenderDrawPoint((int)objects.at(i).get_x_position(), (int)objects.at(i).get_y_position());
    }

    return;
}

int main(int argc, char *argv[])
{

    try
    {
        float timestep = 0.1;

        vector<object> objects;
        // vector<Draw> drawings;
        Draw example;
        object one(objects, pow(10, 15), 0, 0, 400, 300);
        object two(objects, pow(10, 1), 0, -25, +50 + 400, +50 + 300);

        std::cout << "past example" << std::endl;
        for (size_t i = 0; i < 255; i++)
        {
            calculateUpdateVelocity(objects, timestep);
            calcualteUpdatePosition(objects, example, timestep, i);
            example.RenderPresent();
        }

        char s;
        std::cin >> s;
    }
    catch (const char *e)
    {
        cerr << e << endl;
    }

    return 0;
}