/*Weather Data Analysis (2D Dynamic Array)
Background: You are working on a program to analyze weather data for a city. The data is collected
daily for a month, and you need to store and process it.
Task:
1. Ask the user to input the number of days in the month (e.g., 28, 30, or 31).

2. Dynamically allocate a 2D array to store the temperature data for each day 
(rows = days, columns= 3 for min, max, and average temperature).

3. Populate the array with user-provided temperature data.

4. Perform the following analysis:
	• Find the hottest and coldest day of the month.
	• Calculate the monthly average temperature.
	• Display the temperature trends (e.g., days with increasing max temperature).
	
5. Deallocate the memory after use.
Real-world connection: This scenario simulates real-world weather data analysis, where data is
stored in a tabular format and processed for insights.*/
  
#include<iostream>
#include<iomanip>
#include<iomanip>
using namespace std;
void display(int** , int );
void display(int** weather, int row)
{
		// display elements	
	cout<<setw(5)<<"\n-----"<<setw(10)<<"---------"<<setw(10)<<"---------"<<setw(10)<<"---------";
	cout<<setw(5)<<"\n Day "<<setw(10)<<" Minimum "<<setw(10)<<" Maximum "<<setw(10)<<" Average";
	for(int i = 0; i < row; i ++)
	{cout<<"\n";
	cout<<setw(5)<<(i+1)<<setw(10)<<weather[i][0]<<setw(10)<<weather[i][1]<<setw(10)<<weather[i][2];
	}
	cout<<setw(5)<<"\n-----"<<setw(10)<<"---------"<<setw(10)<<"---------"<<setw(10)<<"---------";	
}

 int main()
 {
  	int row, col = 3; 
 	
//  1. Ask the user to input the number of days in the month (e.g., 28, 30, or 31)
 	cout<<"\nEnter number of days in month: ";
 	cin>>row;
 	
// 2. Dynamically allocate a 2D array to store the temperature data for each day (rows = days, columns = 3
//   for min, max, and average temperature).
 	int** weather = new int*[row];
 	// for each row allocate memory in new array
	 for (int i = 0; i < row; i ++)
	  {
	 	weather[i] = new int[col];	 	
	  } 
	
// 3. Populate the array with user-provided temperature data  .
	cout<<"\nInput Weather Data";
	for(int i = 0; i < row; i ++)
	{
		cout<<"\nMinimum Temperature for day "<<(i+1)<<" : ";
		cin>>weather[i][0];
		cout<<"Maximum Temperature for day "<<(i+1)<<" : ";
		cin>>weather[i][1];
		weather[i][2] = ( weather[i][0] + weather[i][1])/2.0f;
		cout<<"Average Temperature for day "<<(i+1)<<" : "<<weather[i][2]<<endl;	
	}
		// display elements
	display(weather, row);
	
//4. Perform the following analysis:
//
//• Find the hottest and coldest day of the month.
// we iterate for all days of a months max temp and store in hot and vice vera for cold one
	int hot = weather[0][0], cold = weather[0][1], h_index, c_index;
	int monthly_average = 0;
	for(int i = 0; i < row; i ++)
	{
			if ( hot < weather[i][1])
			{
				hot = weather[i][1];
				h_index = (i+1);
			
			}
			if( cold > weather[i][0])
			{
				cold = weather[i][0];
				c_index = (i+1);
				
			}
// Calculating the monthly average temperature
// we iterate through the 3rd column of each row
		monthly_average += weather[i][2];

	}
	cout<<"\nhottest day of month is "<<h_index<<" and the temperature is "<<hot<<endl;
	cout<<"coldest day of month is "<<c_index<<" and the temperature is "<<cold<<endl;
	cout<<"\nMonthly average temperature is "<<( monthly_average/row)<<endl;
	

     // • Display the temperature trends (e.g., days with increasing max temperature).
    int start_inc = 0, end_inc = 0;
    int start_dec = 0, end_dec = 0;

    for (int i = 0; i < row - 1; i++)
    {
        // Check for increasing trend
        if (weather[i + 1][1] > weather[i][1])
        {
            if (start_inc == 0) // Start of increasing trend
                start_inc = i;
            
            end_inc = i + 1; // Update end of increasing trend
        }
        else
        {
            if (start_inc != 0) // End of increasing trend
            {
                cout << "\nMax Temp increases from day " << ( start_inc+1) << " to day " << ( end_inc+1);
                start_inc = 0; // Reset for next trend
            }
        }

        // Check for decreasing trend
        if (weather[i + 1][1] < weather[i][1])
        {
            if (start_dec == 0) // Start of decreasing trend
                start_dec = i + 1;
    
            end_dec = i + 2; // Update end of decreasing trend
        }
        else
        {
            if (start_dec != 0) // End of decreasing trend
            {
                cout << "\nMax Temp decreases from day " << start_dec << " to day " << end_dec;
                start_dec = 0; // Reset for next trend
            }
        }
    }
    // Handle cases where the trend continues until the last day
    if (start_inc != 0)
        cout<<"\nMax Temp increases from day "<<start_inc<<" to day "<<end_inc;
    
    if (start_dec != 0)
        cout<< "\nMax Temp decreases from day "<<start_dec<<" to day "<<end_dec;
    
    // 5. Deallocate the memory after use.
    for (int i = 0; i < row; i++)
    {
        delete[] weather[i];
    }
    delete[] weather;
	return 0;
 }




