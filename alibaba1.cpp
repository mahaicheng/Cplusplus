vector<double> BatchQueryExecutionTime(const vector<string> &sqls, const vector<double> &times, const vector<string> &keywords)
{
    if (sqls.empty() || times.empty() || keywords.empty())
        return vector<double>();

    if (sqls.size() != times.size())
        return vector<double>();

    unordered_map<string, int> num;
    unordered_map<string, double> avgVal;

    vector<string> strVec;

    int n = 0; // the nth line
    for (const auto &str1 : sqls)
    {
        strVec = split(str1);

        for (const auto &str : strVec)
        {
            if (avgVal.find(str) == avgVal.end())
            {
                avgVal[str] = times[n];
                num[str] = 1;
            }
            else
            {
                avgVal[str] = (double)(avgVal * num[str] + times[n]) / (num[str] + 1);
                num[str]++;
            }
        }
        n++;
    }

    vector<double> result;
    for (const auto &str : keywords)
    {
        if (avgVal.find(str) == avgVal.end())
        {
            result.push_back(0.0);
        }
        else
        {
            result.push_back(avgVal[str]);
        }
    }

    return result;
}

vector<string> split(const string &str)
{
    if (str.empty())
        return vector<string>();

    vector<string> result;

    int start = 0, end = 0;
    while (start != string::npos)
    {
        start = str.find_first_not_of(' ', start);
        end = str.find_first_of(' ', start);

        if (start == string::npos)
            break;
        if (end == string::npos)
        {
            result.push_back(str.substr(start));
            break;
        }
        else
        {
            result.push_back(str.substr(start, distance(start, end)));
            start = end + 1;
        }
    }

    return result;
}
