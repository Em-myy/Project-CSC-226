#include <iostream>
#include <vector> // This is a library that allows us to create dynamic arrays.
#include <string>
#include <map> // This is a library that allow us to store the locations in a manner that it will be a key value pair.
using namespace std;

//The first class, this class is the base class in which we will use to define our routes.
class RouteInfo {
	private:
        // This initialize an array named path and we set it as a private property so only the class RouteInfo can access it.
		vector<string> path; 

        // This also initialize the maximum and minimum cost and set it that only the RouteInfo can access it.
		int minCost, maxCost; 
	public:
        // This also set a constructor but this will run when we create an object that does not have any arguement
		RouteInfo() : minCost(-1), maxCost(-1) {};

        //This set a constructor for the RouteInfo class so that when any object with arguements is created from the RouteInfo class this constructor will run. 
		RouteInfo(vector<string> p, int minC, int maxC) : path(move(p)), minCost(minC), maxCost(maxC) {}; 

        //This is a function that just helps to show our minimum and maximum scores. This won't return any value.
		void display() const {
			std::cout << "Route: " << endl;
			for (int i = 0; i < path.size(); ++i) {
                std::cout << path[i] << endl;;

				if (i < path.size() - 1) {
                    std::cout << "->" << endl;
				}
			}
			std::cout << "Cost: #" << minCost << " - #" << maxCost << endl;
		}

        //This is also a function but it will return a value of either true or false
		bool isValid() const {
			return !path.empty();
		}
};

//This is the class that handles the route logic
class RouteManager {
    //This is where we declare the map with our key value pair that we will use
	private:
		map<pair<string, string>, RouteInfo> routeMap;

        //This is to make sure that a, b is the same thing as b, a. so like ikeja, CMS is the same as CMS, ikeja
		pair<string, string> makeKey(const string& a, const string& b) const {
			return (a < b) ? make_pair(a, b) : make_pair(b, a);
		};
	public:
        /*This function too won't return anything but it will be able to use the map that we declare as private above since it is also inside the same class
		The way it works is that we make the locations key and the value is the route with the minimum and maximum prices.*/
		void initializeRoutes() {
			//Routes For Ikeja.
			routeMap[makeKey("Ikeja", "Oshodi")] = RouteInfo({ "Ikeja", "Maryland", "Oshodi" }, 1000, 2500);
			routeMap[makeKey("Ikeja", "Ikotun")] = RouteInfo({ "Ikeja", "Iyana Ipaja", "Egbeda", "Ikotun" }, 1500, 2500);
			routeMap[makeKey("Ikeja", "CMS")] = RouteInfo({ "Ikeja", "Oshodi", "Ojuelegba", "CMS" }, 2000, 4500);
			routeMap[makeKey("Ikeja", "Yaba")] = RouteInfo({ "Ikeja", "Ojota", "Fadeyi", "Yaba" }, 1200, 3000);
			routeMap[makeKey("Ikeja", "Lekki")] = RouteInfo({ "Ikeja", "CMS", "Lekki Toll", "Lekki" }, 2500, 4000);
			routeMap[makeKey("Ikeja", "Ojo (LASU Gate)")] = RouteInfo({ "Ikeja", "Oshodi", "Mile 2", "Ojo (LASU Gate)" }, 1500, 3500);
			routeMap[makeKey("Ikeja", "Agege")] = RouteInfo({ "Ikeja", "Agege" }, 500, 1000);
			routeMap[makeKey("Ikeja", "Badagry")] = RouteInfo({ "Ikeja", "Agege", "Ikotun", "Ojo (LASU Gate)", "Badagry" }, 3000, 4000);
			routeMap[makeKey("Ikeja", "Mushin")] = RouteInfo({ "Ikeja", "Agege", "Mushin" }, 1500, 2000);

			//Routes For Oshodi
			routeMap[makeKey("Oshodi", "Ikotun")] = RouteInfo({ "Oshodi", "Cele Express", "Iyana Ejigbo", "Ikotun" }, 1000, 2500);
			routeMap[makeKey("Oshodi", "CMS")] = RouteInfo({ "Oshodi", "Ojuelegba", "CMS" }, 2500, 4000);
			routeMap[makeKey("Oshodi", "Yaba")] = RouteInfo({ "Oshodi", "Fadeyi", "Yaba" }, 1500, 3000);
			routeMap[makeKey("Oshodi", "Lekki")] = RouteInfo({ "Oshodi", "CMS", "Lekki" }, 2000, 2500);
			routeMap[makeKey("Oshodi", "Ojo (LASU Gate)")] = RouteInfo({ "Oshodi", "Mile 2", "Ojo (LASU Gate)" }, 2500, 4000);
			routeMap[makeKey("Oshodi", "Agege")] = RouteInfo({ "Oshodi","Mushin", "Ikeja", "Agege" }, 1000, 1500);
			routeMap[makeKey("Oshodi", "Badagry")] = RouteInfo({ "Oshodi", "Ikotun", "Ojo (LASU Gate)", "Badagry" }, 3500, 4000);
			routeMap[makeKey("Oshodi", "Mushin")] = RouteInfo({ "Oshodi", "Mushin" }, 500, 1000);

			//Routes For Ikotun
			routeMap[makeKey("Ikotun", "CMS")] = RouteInfo({ "Ikotun", "Igando", "Mile 2", "CMS" }, 2500, 5000);
			routeMap[makeKey("Ikotun", "Yaba")] = RouteInfo({ "Ikotun", "Egbeda", "Iyana Ipaja", "Yaba" }, 3000, 3500);
			routeMap[makeKey("Ikotun", "Lekki")] = RouteInfo({ "Ikotun", "Mile 2", "CMS", "Lekki" }, 2500, 3500);
			routeMap[makeKey("Ikotun", "Ojo (LASU Gate)")] = RouteInfo({ "Ikotun", "Igando", "Ojo (LASU Gate)" }, 1000, 1500);
			routeMap[makeKey("Ikotun", "Agege")] = RouteInfo({ "Ikotun", "Egbeda", "Agege" }, 1500, 2000);
			routeMap[makeKey("Ikotun", "Badagry")] = RouteInfo({ "Ikotun", "Ojo (LASU Gate)", "Badagry" }, 3500, 4500);
			routeMap[makeKey("Ikotun", "Mushin")] = RouteInfo({ "Ikotun", "Agege", "Ikeja", "Oshodi", "Mushin" }, 3500, 5000);

			//Route Map For CMS
			routeMap[makeKey("CMS", "Yaba")] = RouteInfo({ "CMS", "Ojuelegba", "Yaba" }, 2000, 4500);
			routeMap[makeKey("CMS", "Lekki")] = RouteInfo({ "CMS", "Lekki Toll", "Lekki" }, 1000, 3000);
			routeMap[makeKey("CMS", "Ojo (LASU Gate)")] = RouteInfo({ "CMS", "Mile 2", "Ojo (LASU Gate)" }, 2000, 4000);
			routeMap[makeKey("CMS", "Agege")] = RouteInfo({ "CMS", "Mushin", "Ikeja", "Agege" }, 2500, 3500);
			routeMap[makeKey("CMS", "Badagry")] = RouteInfo({ "CMS", "Ikotun", "Ojo (LASU Gate)", "Badagry" }, 2500, 4000);
			routeMap[makeKey("CMS", "Mushin")] = RouteInfo({ "CMS", "Ikeja", "Mushin" }, 500, 2000);

			//Route Map For Yaba
			routeMap[makeKey("Yaba", "Lekki")] = RouteInfo({ "Yaba", "CMS", "Lekki" }, 2000, 3000);
			routeMap[makeKey("Yaba", "Ojo (LASU Gate)")] = RouteInfo({ "Yaba", "Ojuelegba", "Mile 2", "Ojo (LASU Gate)" }, 2500, 4000);
			routeMap[makeKey("Yaba", "Agege")] = RouteInfo({ "Yaba", "Ikeja", "Agege" }, 500, 2000);
			routeMap[makeKey("Yaba", "Badagry")] = RouteInfo({ "Yaba", "Ikeja", "Agege", "Ikotun", "Ojo (LASU Gate)", "Badagry" }, 3500, 6000);
			routeMap[makeKey("Yaba", "Mushin")] = RouteInfo({ "Yaba", "Mushin" }, 500, 1000);

			//Route Map For Lekki
			routeMap[makeKey("Lekki", "Ojo (LASU Gate)")] = RouteInfo({ "Lekki", "Agege", "Ikotun", "Ojo (LASU Gate)" }, 1500, 4000);
			routeMap[makeKey("Lekki", "Agege")] = RouteInfo({ "Lekki", "Ikeja", "Agege" }, 1000, 2000);
			routeMap[makeKey("Lekki", "Badagry")] = RouteInfo({ "Lekki", "Agege", "Ikotun", "Ojo (LASU Gate)", "Badagry" }, 2500, 5500);
			routeMap[makeKey("Lekki", "Mushin")] = RouteInfo({ "Lekki", "Oshodi", "Mushin" }, 1500, 4000);

			//Route Map For Ojo (LASU Gate)
			routeMap[makeKey("Ojo (LASU Gate)", "Agege")] = RouteInfo({ "Ojo (LASU Gate)", "Ikotun", "Agege" }, 500, 1500);
			routeMap[makeKey("Ojo (LASU Gate)", "Badagry")] = RouteInfo({ "Ojo (LASU Gate", "Badagry" }, 1000, 3000);
			routeMap[makeKey("Ojo (LASU Gate)", "Mushin")] = RouteInfo({ "Ojo (LASU Gate)", "Agege", "Ikeja", "Oshodi", "Mushin" }, 3000, 6000);

			//Route Map For Agege
			routeMap[makeKey("Agege", "Badagry")] = RouteInfo({ "Agege", "Ikotun", "Ojo (LASU Gate)", "Badagry" }, 2000, 5000);
			routeMap[makeKey("Agege", "Mushin")] = RouteInfo({ "Agege", "Oshodi", "Mushin" }, 1500, 3000);

			//Route Map for Badagry And Mushin
			routeMap[makeKey("Badagry", "Mushin")] = RouteInfo({ "Badagry", "Ojo (LASU Gate)", "Ikotun", "Oshodi", "Mushin" }, 4500, 6000);
		};

		/*This is the function that once we can collect the user input we will turn it to a key and look for that particular key value pair
		 so once we can get the key and it is valid that the routeInfo that we declare in the routemap then we will return it.*/
		RouteInfo getRoute(const string& start, const string& end) const {
			auto key = makeKey(start, end);
			auto it = routeMap.find(key);
			if (it != routeMap.end()) {
				return it->second;
			}
			return RouteInfo();
		}
};


//This is the final class and it handles interaction with the user and it calls the two classes defined above.
class BusRouteFinder {
	private:
		//This is us making an object of class RouteManager and setting it as private so that we can only access it from inside this class.
		RouteManager routeManager;

		//These are the locations that we use to create our map.
		vector<string> locations = { "Ikeja", "Oshodi", "Ikotun", "CMS", "Yaba", "Lekki", "Ojo (LASU Gate)", "Agege", "Badagry", "Mushin" };
	public:
		//This is the main function that uses everything that we have been declaring.
		void run() {
			//This is when we are calling that initialize routes that has all the mapping we did in the former class.
			routeManager.initializeRoutes();

			string username;
			std::cout << "Please enter your name: " << endl;
			getline(cin, username);

			std::cout << "Hello " << username << "!. Let us help you find you way in this very bustling city" << endl;
            std::cout << "Please enter where you are and the place you are going to: " << endl;

			char again = 0;
			
			do {
				//This function is declared below but i am calling it now.
				displayLocations();

				int startChoice, endChoice;
				std::cout << "Enter number for start location: ";
				std::cin >> startChoice;
				std::cout << "Enter number for your destination: ";
				std::cin >> endChoice;

				//This is when we want to get  the text from the number the user picked
				string start = locations[startChoice - 1];
				string end = locations[endChoice - 1];

				std::cout << "Dear " << username << ". You are at " << start << " and you want to go to " << end << ". This is your result." << endl;

				//This isValidChoice is also declared below.
				if (!isValidChoice(startChoice) || !isValidChoice(endChoice)) {
					std::cout << "Invalid Choice. Try Again" << endl;
					continue;
				}

				if (start == end) {
					std::cout << "You are already at your location" << endl;
				}
				else {
					/*Here we are calling both the RouteInfo class and the RouteManager class and we are now using that 
					getRoute function that we declared to search for the value from the start and end locations the user inputted*/
					RouteInfo route = routeManager.getRoute(start, end);
					if (route.isValid()) {
						route.display();
					}
					else {
						std::cout << "No route found between " << start << " and " << end << endl;
					}
				};
				std::cout << "Do you want to check for another route? (y/n): ";
				std::cin >> again;
			} while (again == 'y' || again == 'Y');

			std::cout << "Thanks for trusting us to help you find your way. We look forward to seeing you again." << endl;
		};

		/*We have called this function inside the run function so all it does is to display the locations we have declared 
		in a numbered fashion and also it does not return any value. This function is not returning anything.*/
		void displayLocations() {
			std::cout << "=== Available Locations: ===" << endl;
			for (int i = 0; i < locations.size(); ++i) {
				std::cout << i + 1 << ". " << locations[i] << endl;
			}
		};

		/*This checks if the number the user inputted is greater or lesser than the numbers that we can compare
		so essentially if we are showing 1 to 5 and the user picks 8, this is the function that will check it and it will return 
		either true or false.*/
		bool isValidChoice(int choice) const {
			return choice >= 1 && choice <= (int)locations.size();
		};
};

int main() {
	//This is us calling the last class and making an object of it.
	BusRouteFinder app;
	//This is the function that we declared as a public property.
	app.run();
	return 0;
}
