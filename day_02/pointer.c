#include <stdio.h>

struct Sensor {
    int id;
    int temperature;
};

union Data {
    int number;
    char character;
};

enum DeviceState {
    DEVICE_OFF,
    DEVICE_STARTING,
    DEVICE_RUNNING,
    DEVICE_ERROR
};

void swap_tempereture(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int find_max(const int values[], size_t count)
{
    int max = values[0];
    for (size_t i=1 ; i<count ; i++)
    {
        if (values[i]>max)
        {
            max=values[i];
        }
    }
    return max;
}

int update_temperature(struct Sensor *sensor, int new_temperature)
{
    if (new_temperature < -400 || new_temperature > 1250) {
        return 0;
    }

    sensor->temperature = new_temperature;
    return 1;
}

void print_sensor(const struct Sensor *sensor)
{
    const char *status;

    if (sensor->temperature < 350) {
        status = "NORMAL";
    } else if (sensor->temperature < 450) {
        status = "WARNING";
    } else {
        status = "DANGER";
    }

    printf("Sensor %d: %.1f C | %s\n",
           sensor->id,
           sensor->temperature / 10.0,
           status);
}


int main(void) {
    //exm 1
    int sensor_a = 320;
    int sensor_b = 450;
    
    printf("Before swap: sensor_a =%d, sensor_b = %d\n",sensor_a,sensor_b);
  
    swap_tempereture(&sensor_a,&sensor_b);


    printf("After swap: sensor_a =%d, sensor_b= %d\n",sensor_a,sensor_b);

    //exm 2
    int temperatures[] = {320, 385, 470, 295, 410};
    // size_t count = sizeof(temperatures)/sizeof(temperatures[0]);
    size_t count = sizeof(temperatures)/sizeof(temperatures[0]);
    int max_temp= find_max(temperatures,count);
    printf("Max temperature: %d\n",max_temp);

    //exm 3
    struct Sensor sensor = {
            .id = 1,
            .temperature = 250
        };  

    int new_values[] = {350, 450, 1300};
    size_t new_values_count = sizeof(new_values) / sizeof(new_values[0]);

    print_sensor(&sensor);

    for (size_t i = 0; i < new_values_count; i++) {
        int success = update_temperature(&sensor, new_values[i]);

        printf("Update %d: %s\n",
               new_values[i],
               success ? "OK" : "INVALID");

        print_sensor(&sensor);
    }
    return 0;
}