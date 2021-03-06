package shop;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Shop {
	private static Scanner customer;

	/**
	 * 
	 * ProductStock.shopStock. * @param args
	 */
	public static void main(String[] args) {
		// Customer customer1 = new Customer("Donal", 120);
		Product product = new Product();
		Shop shop = new Shop();
		shop.readAndStore(product);

		// ArrayList<String> arrkeys = new ArrayList<String>();
		try {
			System.out.println("******* WELCOME TO THE SHOP *******");
			while (true) {

				customer = new Scanner(System.in);
				System.out.println(
						"Please enter 1 for standard Customer\nEnter 2 for Bulk orders\nOR\n0(zero) to exit\n");

				int choice = Integer.parseInt(customer.nextLine()); // Read user input
				System.out.println("Debug Customer choice is: " + choice); // Output user input
				if (choice == 1) {
					System.out.println("Please enter your name:");
					String custName = customer.nextLine().toLowerCase().trim(); // Read user input
					System.out.println("Debug main shop: custName: " + custName);
					System.out.println("please enter your budget");
					int custBudget = customer.nextInt();
					Customer customer1 = new Customer(custName, custBudget);
					System.out.println("Debug Customer choice is: " + choice); // Output user input
					product.printProducts();
					shop.checkOut(product, customer1);

				} else if (choice == 2) {
					System.out.println("Please enter your name:");
					String custName = customer.nextLine().toLowerCase().trim(); // Read user input
					System.out.println("Debug main shop: custName: " + custName);
					System.out.println("please enter your budget");
					int custBudget = customer.nextInt(); // Read user input
					// System.out.println("please enter fileName");
					// nt custBudget = customer.nextInt();
					Customer customer1 = new Customer(custName, custBudget);
					product.printProducts();
					shop.BulkCheckOut(product, customer1, "bulkOrder1.csv");
				} else if (choice == 0) {
					System.out.println("Thank You !\nGoodbye "); // Output user input
					System.out.println("Call order review"); // Output user input
					break;
				} else {
					throw new InputMismatchException("incorrect input - You must enter 1,2 or 0.");
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
			System.out.println("user input error must be number");
		}
	}

	/**
	 * @param product
	 * @param cust
	 */
	public void checkOut(Product product, Customer cust) {
		HashMap<String, Integer> custOrdered = new HashMap<String, Integer>();
		// customer order
		//custOrdered = product.Order();
		if (cust.getBudget() < product.productsTotal) {
			System.out.println(cust + " ordered " + custOrdered.toString());
			System.out.printf("Total cost is \u20ac%.2f\n", product.productsTotal);
			System.out.println("**** Checking Budget ****");
			System.out.println("**** Sorry you do not have enough money ****");
		} else {
			System.out.println(cust + " ordered " + custOrdered.toString());
			System.out.printf("Total cost is \u20ac%.2f\n", product.productsTotal);
			System.out.println("**** Budget checked! ****");
			double moneyReturned = cust.getBudget() - product.productsTotal;
			cust.setBudget(moneyReturned);
			System.out.printf("**** budget remaining \u20ac%.2f  ****", moneyReturned);
			// update stock.
			product.updateStock(custOrdered);
			System.out.println("");
			product.printProducts();
		}
	}

	// bulkOrder1
	public void BulkCheckOut(Product product, Customer cust, String fileName) {
		HashMap custOrdered = new HashMap<String, Integer>();
		// customer order
		custOrdered = product.BulkOrder(fileName);
		if (cust.getBudget() < product.productsTotal) {
			System.out.println(cust + " ordered " + custOrdered.toString());
			System.out.printf("Total cost is \u20ac%.2f\n", product.productsTotal);
			System.out.println("**** Checking Budget ****");
			System.out.println("**** Sorry you do not have enough money ****");
		} else {
			System.out.println(cust + " ordered " + custOrdered.toString());
			System.out.printf("Total cost is \u20ac%.2f\n", product.productsTotal);
			System.out.println("**** Budget checked! ****");
			double moneyReturned = cust.getBudget() - product.productsTotal;
			cust.setBudget(moneyReturned);
			System.out.printf("**** budget remaining \u20ac%.2f  ****", moneyReturned);
			// update stock.
			product.updateStock(custOrdered);
			System.out.println("");
			product.printProducts();
		}
	}

	/**
	 * This void method will read the a CSV file and in a interface called
	 * ProductStore No return
	 */
	public void readAndStore(Product product) {
		String line = "";
		// Product product = new Product();
		BufferedReader br;
		// try the code if the file cant be read, then catch the exception
		try {
			br = new BufferedReader(new FileReader("stockJava.csv"));
			// returns a Boolean value
			while ((line = br.readLine()) != null) {

				product.addToStock(line.substring(0, line.indexOf(",")),
						Integer.parseInt(line.substring(line.lastIndexOf(",") + 1, line.length())));
				// populate Dictionary price with key = name and value = price
				product.addToPrice(line.substring(0, line.indexOf(",")),
						Double.parseDouble(line.substring(line.indexOf(",") + 1, line.lastIndexOf(","))));
			}
		} catch (IOException e) {
			e.printStackTrace();
			System.out.println("File exception IO error");
		}
	}

}
