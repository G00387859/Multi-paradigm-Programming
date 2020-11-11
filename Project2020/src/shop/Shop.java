package shop;

public class Shop {

	public static void main(String[] args) {
		
		Customer customer1 = new Customer("Donal",12);
		Product product = new Product("Bread",12);
		System.out.println(product.stock());
		//System.out.println(customer1.toString());
		
		

	}

}
