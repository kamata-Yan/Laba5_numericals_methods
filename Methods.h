#pragma once
double function(const double& x);
double trapezium_method(double(&function)(const double&), const double& start, const double& end, const unsigned long& n);
double calculate_trapezium_method(double(&function)(const double&), const double& start, const double& end, const double& epsilon);
double simson_method(double(&function)(const double&), const double& start, const double& end, const unsigned long& n);
double calculate_simson_method(double(&function)(const double&), const double& start, const double& end, const double& epsilon);

