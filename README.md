Concepts 
Objects-oriented Programming: classes, encapsulation, constructors, functions
Standard Template Library (STL) Containers: Vector, map, pair
User interaction: cin, cout, loops, conditions
Data Abstraction: Users interact with a simple interface while complex route logic is hidden.

Overview
The Bus Route is a C++ project designed to help users navigate Lagos by providing efficient and affordable bus routes between two locations. It uses Object-oriented programming (OOP) principles in C++ to manage data and interactions effectively.
Purpose 
This project aims to simplify route-finding in Lagos by allowing users to input their starting location and destination. The application then automatically evaluates the best route, along with the minimum and maximum transport fare (T-fare).
How it works
 The Bus Route Finder uses three main classes to handle different aspects of the program:
ROUTE TEMPLATE CLASS
       This is the base class. it defines the template for building routes.
It includes variables and functions that helping storing the route, minimum far, and maximum fare.

ROUTE DATABASE CLASS
         This is the core class that builds upon the template provided by the first class. it defines the actual routes between locations in Lagos. 
Each route contains:
A path (sequence of bus stops or landmarks).
The minimum fare and maximum fare.


A map data structure (key-value pair) is used:
Key: Combinations of starting and ending locations.
Value: the route combinations (path, min fare, max fare). 
USER INTERACTION CLASS 
            This class handles everything related to the user interface.
It: -
Collects the user’s name for personalization.
Accepts starting and destination inputs.
Uses the map from the second class to evaluate and retrieve the route.
Displays the most efficient route, including the minimum and maximum T-fares.
         Input validation is implemented:
If the user makes a mistake (e.g., incorrect spelling of a location), the app prompts them to try again.
This makes it user-friendly, especially for individuals under stress or unfamiliar environments.
  

USAGE INSTRUCTIONS
Launch the app
Enter your name
Input your starting location
Input your destination.
View the recommended route, along with minimum and maximum fares.
