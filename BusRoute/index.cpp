#include <iostream>
        // For input and output
        #include <vector>
            // To use vectors (dynamic arrays)
            #include <string>
                // To use string type
                using namespace std;         // So we don't need to write std:: every time


                // === Class to represent a bus route ===
                class BRTBusRoute {
                private:
                string start, end;              // Start and end locations
                vector<string>
                    path;            // Vector to hold the route (bus stops)
                    int minCost, maxCost;           // Minimum and maximum cost of the trip

                    public:
                    // Constructor to initialize start and end location
                    BRTBusRoute(string s, string e) {
                    start = s;
                    end = e;
                    minCost = maxCost = -1;     // Default values
                    }

                    // Function to calculate route path and fare based on input
                    void calculateRoute() {

                    //Route For Ikeja.
                    if ((start == "Ikeja" && end == "Oshodi") || (start == "Oshodi" && end == "Ikeja")) {
                    path = { "Ikeja", "Maryland", "Oshodi" };
                    minCost = 1000; maxCost = 2500;
                    }
                    else if ((start == "Ikeja" && end == "Ikotun") || (start == "Ikotun" && end == "Ikeja")) {
                    path = { "Ikeja", "Iyana Ipaja", "Egbeda", "Ikotun" };
                    minCost = 1500; maxCost = 2500;
                    }
                    else if ((start == "Ikeja" && end == "CMS") || (start == "CMS" && end == "Ikeja")) {
                    path = { "Ikeja", "Oshodi", "Ojuelegba", "CMS" };
                    minCost = 2000; maxCost = 4500;
                    }
                    else if ((start == "Ikeja" && end == "Yaba") || (start == "Yaba" && end == "Ikeja")) {
                    path = { "Ikeja", "Ojota", "Fadeyi", "Yaba" };
                    minCost = 1200; maxCost = 3000;
                    }
                    else if ((start == "Ikeja" && end == "Lekki") || (start == "Lekki" && end == "Ikeja")) {
                    path = { "Ikeja", "CMS", "Lekki Toll", "Lekki" };
                    minCost = 2500; maxCost = 4000;
                    }
                    else if ((start == "Ikeja" && end == "Ojo (LASU Gate)") || (start == "Ojo (LASU Gate)" && end == "Ikeja")) {
                    path = { "Ikeja", "Oshodi", "Mile 2", "Ojo (LASU Gate)" };
                    minCost = 1500; maxCost = 3500;
                    }
                    else if ((start == "Ikeja" && end == "Agege") || (start == "Agege" && end == "Ikeja")) {
                    path = { "Ikeja", "Agege" };
                    minCost = 500; maxCost = 1000;
                    }
                    else if ((start == "Ikeja" && end == "Badagry") || (start == "Badagry" && end == "Ikeja")) {
                    path = { "Ikeja", "Agege", "Ikotun", "Ojo (LASU Gate", "Badagry" };
                    minCost = 3500; maxCost = 4000;
                    }
                    else if ((start == "Ikeja" && end == "Mushin") || (start == "Mushin" && end == "Ikeja")) {
                    path = { "Ikeja", "Agege", "Mushin" };
                    minCost = 1500; maxCost = 2000;
                    }

                    //Route For Oshodi
                    else if ((start == "Oshodi" && end == "Ikotun") || (start == "Ikotun" && end == "Oshodi")) {
                    path = { "Oshodi", "Cele Express", "Iyana Ejigbo", "Ikotun" };
                    minCost = 1000; maxCost = 2500;
                    }
                    else if ((start == "Oshodi" && end == "CMS") || (start == "CMS" && end == "Oshodi")) {
                    path = { "Oshodi", "Ojuelegba", "CMS" };
                    minCost = 2500; maxCost = 4000;
                    }
                    else if ((start == "Oshodi" && end == "Yaba") || (start == "Yaba" && end == "Oshodi")) {
                    path = { "Oshodi", "Fadeyi", "Yaba" };
                    minCost = 1500; maxCost = 3000;
                    }
                    else if ((start == "Oshodi" && end == "Lekki") || (start == "Lekki" && end == "Oshodi")) {
                    path = { "Oshodi", "CMS", "Lekki" };
                    minCost = 2000; maxCost = 2500;
                    }
                    else if ((start == "Oshodi" && end == "Ojo (LASU Gate)") || (start == "Ojo (LASU Gate)" && end == "Oshodi")) {
                    path = { "Oshodi", "Mile 2", "Ojo (LASU Gate)" };
                    minCost = 2500; maxCost = 4000;
                    }
                    else if ((start == "Oshodi" && end == "Agege") || (start == "Agege" && end == "Oshodi")) {
                    path = { "Oshodi","Mushin", "Ikeja", "Agege" };
                    minCost = 1000; maxCost = 1500;
                    }
                    else if ((start == "Oshodi" && end == "Badagry") || (start == "Badagry" && end == "Oshodi")) {
                    path = { "Oshodi", "Ikotun", "Ojo (LASU Gate", "Badagry" };
                    minCost = 3500; maxCost = 4000;
                    }
                    else if ((start == "Oshodi" && end == "Mushin") || (start == "Mushin" && end == "Oshodi")) {
                    path = { "Oshodi", "Mushin" };
                    minCost = 500; maxCost = 1000;
                    }

                    //Route For Ikotun
                    else if ((start == "Ikotun" && end == "CMS") || (start == "CMS" && end == "Ikotun")) {
                    path = { "Ikotun", "Igando", "Mile 2", "CMS" };
                    minCost = 2500; maxCost = 5000;
                    }
                    else if ((start == "Ikotun" && end == "Yaba") || (start == "Yaba" && end == "Ikotun")) {
                    path = { "Ikotun", "Egbeda", "Iyana Ipaja", "Yaba" };
                    minCost = 3000; maxCost = 3500;
                    }
                    else if ((start == "Ikotun" && end == "Lekki") || (start == "Lekki" && end == "Ikotun")) {
                    path = { "Ikotun", "Mile 2", "CMS", "Lekki" };
                    minCost = 2300; maxCost = 3500;
                    }
                    else if ((start == "Ikotun" && end == "Ojo (LASU Gate)") || (start == "Ojo (LASU Gate)" && end == "Ikotun")) {
                    path = { "Ikotun", "Igando", "Ojo (LASU Gate)" };
                    minCost = 1000; maxCost = 1500;
                    }
                    else if ((start == "Ikotun" && end == "Agege") || (start == "Agege" && end == "Ikotun")) {
                    path = { "Ikotun", "Egbeda", "Agege" };
                    minCost = 1500; maxCost = 2000;
                    }
                    else if ((start == "Ikotun" && end == "Badagry") || (start == "Badagry" && end == "Ikotun")) {
                    path = { "Ikotun", "Ojo (LASU Gate)", "Badagry" };
                    minCost = 3500; maxCost = 4000;
                    }
                    else if ((start == "Ikotun" && end == "Mushin") || (start == "Mushin" && end == "Ikotun")) {
                    path = { "Ikotun", "Agege", "Ikeja", "Oshodi", "Mushin" };
                    minCost = 3500; maxCost = 5000;
                    }

                    //Route For CMS
                    else if ((start == "CMS" && end == "Yaba") || (start == "Yaba" && end == "CMS")) {
                    path = { "CMS", "Ojuelegba", "Yaba" };
                    minCost = 2000; maxCost = 4500;
                    }
                    else if ((start == "CMS" && end == "Lekki") || (start == "Lekki" && end == "CMS")) {
                    path = { "CMS", "Lekki Toll", "Lekki" };
                    minCost = 1000; maxCost = 3000;
                    }
                    else if ((start == "CMS" && end == "Ojo (LASU Gate)") || (start == "Ojo (LASU Gate)" && end == "CMS")) {
                    path = { "CMS", "Mile 2", "Ojo (LASU Gate)" };
                    minCost = 2000; maxCost = 4000;
                    }
                    else if ((start == "CMS" && end == "Agege") || (start == "Agege" && end == "CMS")) {
                    path = { "CMS", "Mushin", "Ikeja", "Agege" };
                    minCost = 2500; maxCost = 3500;
                    }
                    else if ((start == "CMS" && end == "Badagry") || (start == "Badagry" && end == "CMS")) {
                    path = { "CMS", "Ikotun", "Ojo (LASU Gate", "Badagry" };
                    minCost = 2500; maxCost = 4000;
                    }
                    else if ((start == "CMS" && end == "Mushin") || (start == "Mushin" && end == "CMS")) {
                    path = { "CMS", "Ikeja", "Mushin" };
                    minCost = 500; maxCost = 2000;
                    }

                    //Route For Yaba
                    else if ((start == "Yaba" && end == "Lekki") || (start == "Lekki" && end == "Yaba")) {
                    path = { "Yaba", "CMS", "Lekki" };
                    minCost = 2000; maxCost = 3000;
                    }
                    else if ((start == "Yaba" && end == "Ojo (LASU Gate)") || (start == "Ojo (LASU Gate)" && end == "Yaba")) {
                    path = { "Yaba", "Ojuelegba", "Mile 2", "Ojo (LASU Gate)" };
                    minCost = 2500; maxCost = 4000;
                    }
                    else if ((start == "Yaba" && end == "Agege") || (start == "Agege" && end == "Yaba")) {
                    path = { "Yaba", "Ikeja", "Agege" };
                    minCost = 500; maxCost = 2000;
                    }
                    else if ((start == "Yaba" && end == "Badagry") || (start == "Badagry" && end == "Yaba")) {
                    path = { "Yaba", "Ikeja", "Agege", "Ikotun", "Ojo (LASU Gate)", "Badagry" };
                    minCost = 3500; maxCost = 6000;
                    }
                    else if ((start == "Yaba" && end == "Mushin") || (start == "Mushin" && end == "Yaba")) {
                    path = { "Yaba", "Mushin" };
                    minCost = 1000; maxCost = 2000;
                    }

                    //Route For Lekki
                    else if ((start == "Lekki" && end == "Ojo (LASU Gate)") || (start == "Ojo (LASU Gate)" && end == "Lekki")) {
                    path = { "Lekki", "Agege", "Ikotun", "Ojo (LASU Gate)" };
                    minCost = 1500; maxCost = 4000;
                    }
                    else if ((start == "Lekki" && end == "Agege") || (start == "Agege" && end == "Lekki")) {
                    path = { "Lekki", "Ikeja", "Agege" };
                    minCost = 500; maxCost = 1500;
                    }
                    else if ((start == "Lekki" && end == "Badagry") || (start == "Badagry" && end == "Lekki")) {
                    path = { "Lekki", "Agege", "Ikotun", "Ojo (LASU Gate", "Badagry" };
                    minCost = 2500; maxCost = 5000;
                    }
                    else if ((start == "Lekki" && end == "Mushin") || (start == "Mushin" && end == "Lekki")) {
                    path = { "Lekki", "Oshodi", "Mushin" };
                    minCost = 1500; maxCost = 4000;
                    }

                    //Route For Ojo (LASU Gate)
                    else if ((start == "Ojo (LASU Gate)" && end == "Agege") || (start == "Agege" && end == "Ojo (LASU Gate)")) {
                    path = { "Ojo (LASU Gate)", "Ikotun", "Agege" };
                    minCost = 500; maxCost = 1500;
                    }
                    else if ((start == "Ojo (LASU Gate)" && end == "Badagry") || (start == "Badagry" && end == "Ojo (LASU Gate)")) {
                    path = { "Ojo (LASU Gate", "Badagry" };
                    minCost = 1000; maxCost = 3000;
                    }
                    else if ((start == "Ojo (LASU Gate)" && end == "Mushin") || (start == "Mushin" && end == "Ojo (LASU Gate)")) {
                    path = { "Ojo (LASU Gate)", "Agege", "Ikeja", "Oshodi", "Mushin" };
                    minCost = 1000; maxCost = 4000;
                    }

                    //Route For Agege
                    else if ((start == "Agege" && end == "Badagry") || (start == "Badagry" && end == "Agege")) {
                    path = { "Agege", "Ikotun", "Ojo (LASU Gate)", "Badagry" };
                    minCost = 2000; maxCost = 5000;
                    }
                    else if ((start == "Agege" && end == "Mushin") || (start == "Mushin" && end == "Agege")) {
                    path = { "Agege", "Oshodi", "Mushin" };
                    minCost = 1500; maxCost = 3000;
                    }

                    //Route For Badagry
                    else if ((start == "Badagry" && end == "Mushin") || (start == "Mushin" && end == "Badagry")) {
                    path = { "Badagry", "Ojo (LASU Gate)", "Ikotun", "Oshodi", "Mushin" };
                    minCost = 2000; maxCost = 6000;
                    }
                    }

                    // Function to display the calculated route and cost
                    void showRoute() {
                    if (path.empty() && (start != end)) {
                    cout << "\nRoute not found between " << start << " and " << end << endl;
                    }
                    else if (path.empty() && (start == end)) {
                    cout << "You are already in the place you want to go to. Thank You" << endl;
                    }
                    else {
                    cout << "\nRoute: ";
                    for (int i = 0; i < path.size(); i++) {
                    cout << path[i];
                    if (i < path.size() - 1) cout << " → ";
                    }
                    cout << "\nCost: ₦" << minCost << " - ₦" << maxCost << endl;
                    }
                    }
                    };


                    // === List of available locations ===
                    vector<string>
                        locations = {
                        "Lekki", "CMS", "Oshodi", "Ikeja", "Ikotun", "Ojo (LASU Gate)", "Yaba", "Agege", "Badagry", "Mushin"
                        };

                        // === Function to find and display route ===
                        void findRoute() {
                        cout << "=== BRT Bus Route Finder ===\n";
                        cout << "Available Locations:\n";

                        for (int i = 0; i < locations.size(); i++) {
                        cout << i + 1 << ". " << locations[i] << endl;
                        }

                        int startChoice, endChoice;
                        cout << "\nEnter number for Start Location: ";
                        cin >> startChoice;
                        cout << "Enter number for End Location: ";
                        cin >> endChoice;

                        // Validate user input
                        if (startChoice < 1 || startChoice > locations.size() || endChoice < 1 || endChoice > locations.size()) {
                        cout << "\nInvalid input. Please choose numbers from the list.\n";
                        return;
                        }

                        string start = locations[startChoice - 1];
                        string end = locations[endChoice - 1];

                        BRTBusRoute route(start, end);
                        route.calculateRoute();
                        route.showRoute();
                        };


                        // === Main Program ===
                        int main() {
                        char again;
                        string userName;

                        cout << "Please Enter Your name: " << endl;
                        getline(cin, userName);

                        cout << "Dear " << userName << ", Where do you want to go to: " << endl;
                        do {
                        findRoute();

                        cout << "\nDo you want to check another route? (y/n): ";
                        cin >> again;
                        } while (again == 'y' || again == 'Y');

                        cout << "\nThanks for using the BRT Bus Route Finder!\n";
                        return 0;
                        }
