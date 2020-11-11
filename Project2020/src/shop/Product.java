package shop;

import java.util.Dictionary;

public class Product implements ProductStock {
	private String name;
	private int quanitiy;
	
	public Product(String name,int quanitiy) {
		this.name = name;
		this.quanitiy = quanitiy;
		ProductStock.shopStock.put(name, quanitiy);
	}
	
	@SuppressWarnings("unchecked")
	public void addToDict() {
		ProductStock.shopStock.put(name, quanitiy);
		
		
	}
	public Dictionary stock() {
		
		return ProductStock.shopStock;
	}
	

}
