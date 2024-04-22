<H1> COP3530 - Project 3 </h1>
<h1> Finding the top three restaurants in an area using quicksort and heapsort</h1>
<h2> Introduction </h2>
*The purpose of this project is to find the top three restaurants in a given city, zipcode, or state

*This project uses Yelp database as the basis for the data

*User input for this project in order are: State abbreviation, City, Category, and Zipcode

*These inputs are used as filters for the outputted selection of restaurants

*Restaurants are selected from an inserted category and/or city, zipcode, or state
<h2> Example Output </h2>
![image](https://github.com/apopovich1/Best_Fit_Yelp_Reviews/assets/127229110/3389b644-1dff-427d-914f-5834be963695)

<h2> Configuration </h2>
After downloading this project, make a cMake configuration for it. 
Configure the include/rapidjson directory as a library file by right clicking on the directory and marking the directory as a library file. If ../include/rapidjson/document.h shows up as not a file retry this step
Additionally, download and unzip the link to for the dataset using the following link:
Google drive link for Yelp Metadata:[https://drive.google.com/file/d/1IJUUYv_f4AQbjlOwJDVcT4kHRH5nmv-D/view?usp=sharing](url).
Download and unzip this link to get the true JSON file. Add this dataset to cmake-build-debug by pasting it in the directory.
With the configuration from cMake, inclusion of the rapidjson files as library files, and JSON data the project will work as shown on github. 

<h2> Refrences </h2>
Yip, Milo (2015) rapidjson (Version 1.1.0) [source code]. Tencent, [https://github.com/Tencent/rapidjson](url).

Tencent is pleased to support the open source community by making RapidJSON available.

Copyright (C) 2015 THL A29 Limited, a Tencent company, and Milo Yip.

Licensed under the MIT License (the "License"); you may not use this file except
in compliance with the License. You may obtain a copy of the License at

http://opensource.org/licenses/MIT

Unless required by applicable law or agreed to in writing, software distributed 
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR 
CONDITIONS OF ANY KIND, either express or implied. See the License for the 
specific language governing permissions and limitations under the License.

Yelp Inc (2021) Dataset (Version 2.0) [dataset] [https://www.yelp.com/dataset](url)
