#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

const int total_width {70};
const int country_width {20};
const int city_width {20};
const int population_width {15};
const int cost_width {15};

//Assume each contry has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

void display_city(const City &city) {
    std::cout << std::setw(city_width) << std::left << city.name
              << std::setw(population_width) << std::right << city.population
              << std::setw(cost_width) << std::setprecision(2) << std::fixed << std::showpoint << city.cost
              << std::endl;
}

void display_country(const Country &country) {
    std::cout << std::setw(country_width) << std::left << country.name;
    for (size_t i = 0; i < country.cities.size(); i++) {
        display_city(country.cities[i]);
        if(i < country.cities.size() - 1)
            std::cout << std::setw(country_width) << "";
    }
}

void display_tours(const Tours &tours) {
    std::cout << std::setw((total_width + tours.title.length()) / 2) << std::right << tours.title << std::endl << std::endl;
    std::cout << std::setw(country_width) << std::left << "Country"
              << std::setw(city_width) << std::left << "City"
              << std::setw(population_width) << std::right << "Population"
              << std::setw(cost_width) << std::right << "Price"
              << std::endl;
    std::cout <<"----------------------------------------------------------------------" << std::endl;
    for(const auto &country : tours.countries) {
        display_country(country);
    }
}

int main() {
    Tours tours
    { "Tour Ticket Prices from Miami",
        {
            {
                "Colombia", {
                    { "Bogota", 877800, 400.98 },
                    { "Cali", 2401000, 424.12 },
                    { "Medellin", 2464000, 350.98 },
                    { "Cartagena", 972000, 345.34 }
                },
            },
            {
                "Brazil", {
                    { "Rio De Janeiro", 13500000, 567.45 },
                    { "Sao Paulo", 11310000, 975.45 },
                    { "Salvador", 18234000, 855.99 }
                },
            },
            {
                "Chile", {
                    { "Valdivia", 260000, 569.12 },
                    { "Santiago", 7040000, 520.00 }
                },
            },
            {
                "Argentina", {
                    { "Buenos Aires", 3010000, 723.77 }
                }
            },
        }
        
    };
    
    //Unformatted display so you can see how to access the vector elements
//    std::cout << tours.title << std::endl;
//    for(auto country : tours.countries) {   //loop through the countries
//        std::cout << country.name << std::endl;
//        for(auto city : country.cities) {   //loop through the cities for each country
//            std::cout << "\t" << city.name
//                      << "\t" << city.population
//                      << "\t" << city.cost
//                      << std::endl;
//        }
//    }
    
    display_tours(tours);
    
    std::cout << std::endl << std::endl;
    return 0;
}