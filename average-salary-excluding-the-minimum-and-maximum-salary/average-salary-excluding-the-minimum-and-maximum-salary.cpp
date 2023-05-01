class Solution {
public:
    double average(std::vector<int>& salary) {
        const int n = salary.size();

        int max_salary = *std::max_element(salary.begin(), salary.end());
        int min_salary = *std::min_element(salary.begin(), salary.end());
        double average_salary = std::accumulate(salary.begin(), salary.end(), 0.00);

        average_salary -= (max_salary + min_salary);
        average_salary /= (n - 2);

        return average_salary;
    }
};