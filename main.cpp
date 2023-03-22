#include <iostream>
#include <vector>
#include <math.h>
#include "draw.h"
using namespace std;

// Driver Code

class object
{
private:
    double mass = 0;
    float velocity_x = 0;
    float velocity_y = 0;
    double x_position = 0;
    double y_position = 0;

public:
    object(vector<object> &objects, double mass, float velocity_x = 0,
           float velocity_y = 0,
           double x_position = 0,
           double y_position = 0)
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

    double getmass()
    {
        return ((*this).mass);
    }
    double get_x_position()
    {
        return ((*this).x_position);
    }
    double get_y_position()
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

                double distancemagnitude = pow(objects.at(i).get_x_position() - objects.at(j).get_x_position(), 2);
                distancemagnitude = distancemagnitude + pow(objects.at(i).get_y_position() - objects.at(j).get_y_position(), 2);
                distancemagnitude = sqrt(distancemagnitude);
                distancemagnitude = abs(distancemagnitude);
                double force = g * (objects.at(j)).getmass() / pow(distancemagnitude, 2);

                force = force * (objects.at(i)).getmass();

                double x_vector = objects.at(i).get_x_position() - objects.at(j).get_x_position();

                x_vector = -x_vector / distancemagnitude;
                cout << "Force:" << force << "N  | " << endl;
                //  x_vector = abs(x_vector);
                cout << "x_vector:" << x_vector << "N  | " << endl;
                float y_vector = objects.at(i).get_y_position() - objects.at(j).get_y_position();
                y_vector = -y_vector / distancemagnitude;
                // y_vector = abs(y_vector);

                double acceleration = force / objects.at(i).getmass();
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
        cout << "Object:" << i << "| Position:" << objects.at(i).get_x_position() + 400 << ", " << objects.at(i).get_y_position() + 300 << "| Velocity:" << objects.at(i).get_x_velocity() << "ms, " << objects.at(i).get_y_velocity() << endl;

        // cout << i << " vel- " << objects.at(i).get_x_velocity() << "ms, " << objects.at(i).get_y_velocity() << endl;
        if (i == 2)
        {
            example.SetRenderDrawColor(255, 255, 0, 255);
        }
        else
        {
            example.SetRenderDrawColor(255, 255, 255, 255);
        }

        example.RenderDrawPoint((int)((objects.at(i).get_x_position() / pow(10, 9)) + 400), (int)((objects.at(i).get_y_position() / pow(10, 9)) + 300));
    }

    return;
}

int main(int argc, char *argv[])
{

    try
    {
        float timestep = 86400;

        vector<object> objects;
        // vector<Draw> drawings;
        Draw example;
        object Sun(objects, 1.988 * pow(10, 30), 0, 0, 0, 0);
        cout << 1.988 * pow(10, 30) << endl;
        object Earth(objects, 5.97 * pow(10, 24), 0, -29800.0, 150.0 * pow(10, 9), 0);
        // object spacecraft(objects, 500, +7000, -29800.0 - 7000, (150.0 * pow(10, 9)) + 7000, 0);
        object Mercury(objects, 3.285 * pow(10, 23), 0, -47900.0, 50.0 * pow(10, 9), 0);
        std::cout << "past example" << std::endl;
        for (size_t i = 0; i < 365; i++)
        {
            calculateUpdateVelocity(objects, timestep);
            calcualteUpdatePosition(objects, example, timestep, i);
            example.RenderPresent();
            char s;
            std::cin >> s;
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