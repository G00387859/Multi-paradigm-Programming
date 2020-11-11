package shop;

public class Customer {

	private String name;
	private int budget;
	public Customer(String name, int budget) {
		this.name = name;
		this.budget = budget;
	}
	@Override
	public String toString() {
		return "Customer name is " + name + ", budget is " + budget ;
	}
	

}
