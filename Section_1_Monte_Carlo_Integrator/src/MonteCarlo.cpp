#include <iostream>
#include <cmath>
#include <random>
#include <functional>

using namespace std;

bool InsideUnitSphere(double x, double y, double z)
{
    return ((x*x + y*y + z*z) <= 1);
}

double IntegrateMonteCarlo3D(int n_points, int seed, double min, double max, function<bool(double, double, double)> f)
{
    int count = 0;
    // N.B. std::pow with integer arguments can be less efficient than
    // writing the multiplication explicitly, so be careful about using it
    // inside loops for example!
    double VolCube = std::pow((max - min), 3);

    //set up random number generator here
    // unsigned seed = 1; // include a seed for reproduceability
    // std::default_random_engine generator (seed);
    std::mt19937 rng_mt(seed);

    std::uniform_real_distribution<double> uniform_dist (-1.0,1.0);

    auto uniform_dist_generated = std::bind(uniform_dist, rng_mt);
    
    for(int i = 0; i < n_points; i++)
    {
        //generate random points here
        double x = uniform_dist_generated();
        double y = uniform_dist_generated();
        double z = uniform_dist_generated();
        if(f(x, y, z)) count++;
    }

    return static_cast<double>(count) / n_points * VolCube;
}


int main(int argc, char** argv)
{   
    int seed; 
    seed = std::stoi(argv[1]);
    int N_points = 10000;

    double UnitSphereVol = IntegrateMonteCarlo3D(N_points, seed, -1.0, 1.0, &InsideUnitSphere);

    std::cout << "Volume estimate of sphere using " << N_points << " points = " << UnitSphereVol << std::endl;
}