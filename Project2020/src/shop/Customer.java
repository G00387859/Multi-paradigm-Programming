package shop;

public class Customer {

	private String name;
	private double budget;
	public Customer(String name, int budget) {
		this.name = name;
		this.budget = budget;
	}
	public void basket() {
		
		
	}
	public String getName() {
		return name;
	}
	public double getBudget() {
		return budget;
	}
	public void setName(String name) {
		this.name = name;
	}
	public void setBudget(double moneyReturned) {
		this.budget = moneyReturned;
	}
	@Override
	public String toString() {
		return "Customer name is " + name + ", budget is " + budget ;
	}
	
	

}
