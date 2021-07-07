#ifndef INVENTORY_H
#define INVETORY_H
class Inventory
{
private:
	int itemNumber,
		quantity;
	double	cost,
			totalCost;

public:
	Inventory();
	Inventory(int, double, int);
	Inventory(const Inventory&);
	void setItemNumber(int);
	void setQuantity(int);
	void setCost(double);
	void setTotalCost();
	int getItemNumber() const;
	int getQuantity() const;
	double getCost()const;
	double getTotalCost()const;
	void display();
};
#endif 
