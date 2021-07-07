#pragma once
#include <iostream>
using namespace std;

class PrinterJob
{
private:
	const int pagesPerMinute = 10;
	int numberOfPages;
	double timeRequired;
	int priorityLevel;
public:
	PrinterJob(int pagesNum = 0);
	void	setNumberOfPages(int pageNum);
	int		getNumberOfPages() const;
	double	getTimeRequiered() const;
	int		getPriorityLevel() const;
	void	calcTimeRequiered();
	void	determinePriorityLevel();

	friend ostream& operator << (ostream& out, const PrinterJob& aJob);
	bool operator = (const PrinterJob& aJob);
	bool operator > (const PrinterJob& aJob) const;
};

