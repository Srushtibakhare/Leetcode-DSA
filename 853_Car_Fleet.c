#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int position;
    double time;
} Car;

int compare(const void *a, const void *b)
{
    Car *c1 = (Car *)a;
    Car *c2 = (Car *)b;

    return c1->position - c2->position;
}

int carFleet(int target, int position[], int speed[], int n)
{
    Car cars[100];

    for(int i = 0; i < n; i++)
    {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double lastTime = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        if(cars[i].time > lastTime)
        {
            fleets++;
            lastTime = cars[i].time;
        }
    }

    return fleets;
}

int main()
{
    int target = 12;

    int position[] = {10,8,0,5,3};

    int speed[] = {2,4,1,1,3};

    int n = 5;

    printf("Car Fleets = %d\n", carFleet(target, position, speed, n));

    return 0;
}