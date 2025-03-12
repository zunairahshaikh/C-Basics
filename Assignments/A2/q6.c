#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Weather {
    float temp;
    float rain;
    float wind;
};

struct Crop {
    char type[20];
    char stage[20];
    float yield;
    struct Weather *forecast;
};

struct Equipment {
    char name[20];
    char status[20];
    float fuel;
    char schedule[20];
};

struct Sensor {
    float nutrient;
    float pH;
    int pestCount;
};

struct Field {
    float lat;
    float lon;
    float soilHealth;
    float moisture;
    struct Crop *crops;
    struct Equipment *tools;
    struct Sensor *sensors;
    int numCrops;
    int numTools;
    int numSensors;
};

struct Hub {
    struct Field *fields;
    int numFields;
    float yieldPrediction;
};

struct Server {
    struct Hub *hubs;
    int numHubs;
};

void inputWeather(struct Weather *w) {
    printf("Enter temperature, rainfall, and wind: ");
    scanf("%f %f %f", &w->temp, &w->rain, &w->wind);
}

void inputCrop(struct Crop *c, struct Weather *w) {
    printf("Enter crop type, growth stage, and expected yield: ");
    scanf("%s %s %f", c->type, c->stage, &c->yield);
    c->forecast = w;
}

void inputEquipment(struct Equipment *e) {
    printf("Enter equipment name, status, fuel level, and schedule: ");
    scanf("%s %s %f %s", e->name, e->status, &e->fuel, e->schedule);
}

void inputSensor(struct Sensor *s) {
    printf("Enter soil nutrients, pH level, and pest count: ");
    scanf("%f %f %d", &s->nutrient, &s->pH, &s->pestCount);
}

void inputField(struct Field *f) {
    printf("Enter field latitude, longitude, soil health, and moisture: ");
    scanf("%f %f %f %f", &f->lat, &f->lon, &f->soilHealth, &f->moisture);
    
    printf("Enter number of crops: ");
    scanf("%d", &f->numCrops);
    f->crops = malloc(f->numCrops * sizeof(struct Crop));
    for (int i = 0; i < f->numCrops; i++) {
        struct Weather w;
        inputWeather(&w);
        inputCrop(&f->crops[i], &w);
    }

    printf("Enter number of equipment: ");
    scanf("%d", &f->numTools);
    f->tools = malloc(f->numTools * sizeof(struct Equipment));
    for (int i = 0; i < f->numTools; i++) {
        inputEquipment(&f->tools[i]);
    }

    printf("Enter number of sensors: ");
    scanf("%d", &f->numSensors);
    f->sensors = malloc(f->numSensors * sizeof(struct Sensor));
    for (int i = 0; i < f->numSensors; i++) {
        inputSensor(&f->sensors[i]);
    }
}

void inputHub(struct Hub *h) {
    printf("Enter number of fields in this hub: ");
    scanf("%d", &h->numFields);
    h->fields = malloc(h->numFields * sizeof(struct Field));
    for (int i = 0; i < h->numFields; i++) {
        inputField(&h->fields[i]);
    }
}

void inputServer(struct Server *s) {
    printf("Enter number of hubs: ");
    scanf("%d", &s->numHubs);
    s->hubs = malloc(s->numHubs * sizeof(struct Hub));
    for (int i = 0; i < s->numHubs; i++) {
        inputHub(&s->hubs[i]);
    }
}

void displayField(struct Field *f) {
    printf("Field Location: (%.2f, %.2f)\n", f->lat, f->lon);
    printf("Soil Health: %.2f, Moisture: %.2f\n", f->soilHealth, f->moisture);
    for (int i = 0; i < f->numCrops; i++) {
        printf("Crop: %s, Stage: %s, Yield: %.2f\n", f->crops[i].type, f->crops[i].stage, f->crops[i].yield);
    }
    for (int i = 0; i < f->numTools; i++) {
        printf("Equipment: %s, Status: %s, Fuel: %.2f, Schedule: %s\n", f->tools[i].name, f->tools[i].status, f->tools[i].fuel, f->tools[i].schedule);
    }
    for (int i = 0; i < f->numSensors; i++) {
        printf("Sensor: Nutrient: %.2f, pH: %.2f, Pest Count: %d\n", f->sensors[i].nutrient, f->sensors[i].pH, f->sensors[i].pestCount);
    }
}

void displayHub(struct Hub *h) {
    for (int i = 0; i < h->numFields; i++) {
        displayField(&h->fields[i]);
    }
}

void displayServer(struct Server *s) {
    for (int i = 0; i < s->numHubs; i++) {
        displayHub(&s->hubs[i]);
    }
}

int main() {
    struct Server s;
    inputServer(&s);
    displayServer(&s);

    return 0;
}