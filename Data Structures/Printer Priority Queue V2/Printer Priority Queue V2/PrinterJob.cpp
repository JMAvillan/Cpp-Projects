#include "PrinterJob.h"
#include <iomanip>

PrinterJob::PrinterJob(int pagesNum) : numberOfPages(pagesNum)
{
	this->calcTimeRequiered();
	this->determinePriorityLevel();
}

void PrinterJob::setNumberOfPages(int pagesNum)
{
	this->numberOfPages = pagesNum;
}

void PrinterJob::calcTimeRequiered() {
	this->timeRequired = (this->numberOfPages / 10.0);
}

void PrinterJob::determinePriorityLevel()
{
	//Priority 3 being the highest priority and 1 the lowest.
	if (this->numberOfPages <= 10)
		this->priorityLevel = 3;
	else if (this->numberOfPages <= 20)
		this->priorityLevel = 2;
	else if (this->numberOfPages <= 50)
		this->priorityLevel = 1;
}


int PrinterJob::getNumberOfPages() const {
	return this->numberOfPages;
}

double PrinterJob::getTimeRequiered() const {
	return this->timeRequired;
}

int	PrinterJob::getPriorityLevel() const {
	return this->priorityLevel;
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
	this->calcTimeRequiered();
	this->determinePriorityLevel();
	return true;
}

bool PrinterJob::operator > (const PrinterJob& aJob) const
{
	return this->priorityLevel > aJob.getPriorityLevel();
}