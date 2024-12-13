/*
 * CS106L Assignment 4: Weather Forecast
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 */

#include <algorithm>
#include <random>
#include <vector>
#include <iostream>


/* #### Please feel free to use these values, but don't change them! #### */
double kMaxTempRequirement = 5;
double uAvgTempRequirement = 60;

struct Forecast {
  double min_temp;
  double max_temp;
  double avg_temp;
};

Forecast compute_forecast(const std::vector<double>& dailyWeather) {
  // STUDENT TODO 1: return a forecast for the daily weather that is passed in.
	Forecast forecast;
	auto begin = dailyWeather.begin();
	auto end = dailyWeather.end();
	int n = dailyWeather.size();
	auto avg = [n]( double sum ,double  x ){return sum + x/n; };
	double min_ele = *std::min_element(begin,end);
	double max_ele = *std::max_element(begin,end);
	double  avg_ele = std::accumulate(begin,end,0.0,avg);
	forecast.min_temp=min_ele;
	forecast.max_temp=max_ele;
	forecast.avg_temp=avg_ele;
	return forecast;
}

std::vector<Forecast> get_forecasts(const std::vector<std::vector<double>>& weatherData) {
  /*
   * STUDENT TODO 2: returns a vector of Forecast structs for the weatherData which contains
   * std::vector<double> which contain values for the weather on that day.
   */
	auto begin=weatherData.begin();
	auto end=weatherData.end();
	std::vector<Forecast> forecast;
	forecast.reserve(weatherData.size());
	std::transform(begin,end,forecast.begin(),[](const std::vector<double>& x){return compute_forecast(x);});
	return forecast;


}

std::vector<Forecast> get_filtered_data(const std::vector<Forecast>& forecastData) {
  // STUDENT TODO 3: return a vector with Forecasts filtered for days with specific weather.
	std::vector<Forecast> filteredData=forecastData;
	auto begin = filteredData.begin();
	auto end = filteredData.end();
	double kMaxTempRequirement=5;
	double uAvgTempRequirement=60;
	auto filtered=[kMaxTempRequirement,uAvgTempRequirement](Forecast x){ return (x.max_temp-x.min_temp)<=kMaxTempRequirement && x.avg_temp<uAvgTempRequirement;};
	auto new_end=std::remove_if(begin,end,filtered);	
	filteredData.erase(new_end,end);
	return filteredData;

}


std::vector<Forecast> get_shuffled_data(const std::vector<Forecast>& forecastData) {
  // STUDENT TODO 4: Make use of a standard library algorithm to shuffle the data!
	std::random_device rd;
	std::mt19937 g(rd());
	std::vector<Forecast> shuffledData = forecastData;
	auto begin = shuffledData.begin();
	auto end = shuffledData.end();
	std::shuffle(begin,end,g);
	return forecastData;
}

std::vector<Forecast> run_weather_pipeline(const std::vector<std::vector<double>>& weatherData) {
  // STUDENT TODO 5: Put your functions together to run the weather pipeline!
	auto forecast = get_forecasts(weatherData);
	auto filtered = get_filtered_data(forecast);
	auto shuffled = get_shuffled_data(filtered);
	return shuffled;
}


/* #### Please don't change this line! #### */
#include "utils.cpp"
