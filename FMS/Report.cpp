void Report::AddToFileWeekRatingByCategory(ReportGenerator rp, Date date, vector<User*>& accounts) 
{
  vector<Category> categoryVect;
  vector<int> categoryVectCount;
  report = rp.generateWeekReport(date, accounts);
  for (auto el : report) 
  {
    for (auto elem : el.second) 
    {
      Category tmp = elem.GetECategory();
      for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] != tmp) categoryVect.push_back(tmp);
    }
  }
  for (int i = 0; i < categoryVect.size(); i++) 
  {
    int count = 0;
    Category tmp = categoryVect[i];
    for (auto el : report) 
    {
      for (auto elem : el.second) 
      {
        Category tmp = elem.GetECategory();
        for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] == tmp) count++;
      }
    }
    categoryVectCount.push_back(count);
  }
  multimap<int, Category> CategoryMap;
  for (int i = 0; i < categoryVect.size(); i++) CategoryMap.insert({ categoryVectCount[i], categoryVect[i] });

  string result;
  for (auto el : CategoryMap) 
  {
    result += to_string(el.first) + ":\n";
    for (int i = 0; i < 3; i++) result += " " + el.second.toString() + "\n";
    result += "\n";
  }
  char* charArray = new char[result.length() + 1];
  strcpy_s(charArray, result.length() + 1, result.c_str());
  ofstream RatingDB("WeekRatingByCategoryDB.dat", ios::binary);
  RatingDB.write(charArray, report.size() * sizeof(report));
  RatingDB.close();
}

void Report::AddToFileMonthRatingByCategory(ReportGenerator rp, Date date, vector<User*>& accounts) 
{
  vector<Category> categoryVect;
  vector<int> categoryVectCount;
  report = rp.generateMonthReport(date, accounts);
  for (auto el : report) 
  {
    for (auto elem : el.second) 
    {
      Category tmp = elem.GetECategory();
      for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] != tmp) categoryVect.push_back(tmp);
    }
  }
  for (int i = 0; i < categoryVect.size(); i++) 
  {
    int count = 0;
    Category tmp = categoryVect[i];
    for (auto el : report) 
    {
      for (auto elem : el.second) 
      {
        Category tmp = elem.GetECategory();
        for (int i = 0; i < categoryVect.size(); i++) if (categoryVect[i] == tmp) count++;
      }
    }
    categoryVectCount.push_back(count);
  }
  multimap<int, Category> CategoryMap;
  for (int i = 0; i < categoryVect.size(); i++) CategoryMap.insert({ categoryVectCount[i], categoryVect[i] });

  string result;
  for (auto el : CategoryMap) 
  {
    result += to_string(el.first) + ":\n";
    for (int i = 0; i < 3; i++) result += " " + el.second.toString() + "\n";
    result += "\n";
  }
  char* charArray = new char[result.length() + 1];
  strcpy_s(charArray, result.length() + 1, result.c_str());
  ofstream RatingDB("MonthRatingByCategoryDB.dat", ios::binary);
  RatingDB.write(charArray, report.size() * sizeof(report));
  RatingDB.close();
}