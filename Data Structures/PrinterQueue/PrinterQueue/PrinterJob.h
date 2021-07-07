#pragma once
#include <iostream>
using namespace std;

class PrinterJob
{
private:
	const int pagesPerMinute = 10;
	int numberOfPages;
	double timeRequired;
public:
	PrinterJob(int pagesNum=0);
	void	setNumberOfPages(int pageNum);
	void	setTimeRequiered();
	int		getNumberOfPages() const;
	double	getTimeRequiered() const;
	void	calcTimeRequiered();
	 
	friend ostream& operator << (ostream& out, const PrinterJob& aJob);
	bool operator = (const PrinterJob& aJob);
	bool operator <= (int numPages ) const;
	bool operator < (int numPages) const;
	bool operator < (const PrinterJob& aJob) const;
	bool operator > (int numPages) const;
};

