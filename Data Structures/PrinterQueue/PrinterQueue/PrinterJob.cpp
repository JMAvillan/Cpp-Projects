#include "PrinterJob.h"
#include <iomanip>

PrinterJob::PrinterJob(int pagesNum) : numberOfPages(pagesNum)
{
	this->setTimeRequiered();
}

void PrinterJob::setNumberOfPages(int pagesNum)
{
	this->numberOfPages = pagesNum;
}

void PrinterJob::setTimeRequiered() {
	this->calcTimeRequiered();
}

void PrinterJob::calcTimeRequiered() {
	this->timeRequired = (this->numberOfPages / 10.0);
}


int PrinterJob::getNumberOfPages() const {
	return this->numberOfPages;
}

double PrinterJob::getTimeRequiered() const {
	return this->timeRequired;
}


ostream& operator << (ostream& out, const PrinterJob& aJob)
{
	out << "Page count: " << aJob.getNumberOfPages() << endl;
	out << "Estimated time: ";
	int integerValue = aJob.getTimeRequiered();
	if (integerValue == 0)
		out << aJob.getTimeRequiered() * 60 - integerValue * 60 << " seconds";

	else if (integerValue * 60 != aJob.getTimeRequiered() * 60)
	{
		out << integerValue;
		if (integerValue == 1)
			out << " minute";
		else
			out << " minutes";
		out << " and " << aJob.getTimeRequiered() * 60 - integerValue * 60 << " seconds";
	}
	else
	{
		out << integerValue;
		if (integerValue == 1)
			out << " minute \n";
		else
			out << "minutes \n";
	}

	return out;
}

bool PrinterJob::operator = (const PrinterJob& aJob) {
	this->setNumberOfPages(aJob.getNumberOfPages());
	this->setTimeRequiered();
	return true;
}

bool PrinterJob::operator <= (int numPages) const
{
	return this->numberOfPages <= numPages;
}

bool PrinterJob::operator < (int numPages) const
{
	return this->numberOfPages < numPages;
}

bool PrinterJob::operator < (const PrinterJob& aJob) const
{
	return this->timeRequired < aJob.getTimeRequiered();
}

bool PrinterJob::operator > (int numPages) const
{
	return this->numberOfPages > numPages;
}