package labpkg;

import java.sql.*;
public class DBConnection{
    DBConnection(){
        try{
            DriverManager.registerDriver(new com.mysql.cj.jdbc.Driver());
        }
        catch(SQLException e){
            e.printStackTrace();
        }
        try{
            Connection myDBConnection = DriverManager.getConnection("jdbc:mysql://localhost:3306/os42", "root", "1234");
            Statement stm = myDBConnection.createStatement();
            
			
			System.out.println("Select Output");
            PreparedStatement selectQuery = myDBConnection.prepareStatement("select * from courses");
			ResultSet rs = selectQuery.executeQuery();
            while(rs.next()){
                System.out.println(rs.getInt(1) + " " + rs.getString(2) + " " +rs.getInt(3));
            }
			System.out.println();
			
			System.out.println("inserting Values (45,SystemAdmin,4)");
			PreparedStatement insertQuery = myDBConnection.prepareStatement("insert into courses values(?,?,?)");
			insertQuery.setInt(1, 45);
            insertQuery.setString(2, "SystemAdmin");
            insertQuery.setInt(3, 4);
            int insertResult = insertQuery.executeUpdate();
            System.out.println(insertResult);
			System.out.println();
			
			System.out.println("Select Output");
            PreparedStatement selectQuery2 = myDBConnection.prepareStatement("select * from courses");
			ResultSet rs2 = selectQuery.executeQuery();
            while(rs2.next()){
                System.out.println(rs2.getInt(1) + " " + rs2.getString(2) + " " +rs2.getInt(3));
            }
			System.out.println();
			         
			System.out.println("update credit hours = 5 where course_id = 3");
			PreparedStatement updateQuery = myDBConnection.prepareStatement("update courses set credit_hour = ? where course_id = 3");
			updateQuery.setInt(1, 5);
			int updateResult = updateQuery.executeUpdate();
            System.out.println(updateResult);
			System.out.println();
			
			System.out.println("Select Output");
            PreparedStatement selectQuery3 = myDBConnection.prepareStatement("select * from courses");
			ResultSet rs3 = selectQuery.executeQuery();
            while(rs3.next()){
                System.out.println(rs3.getInt(1) + " " + rs3.getString(2) + " " +rs3.getInt(3));
            }
			System.out.println();
			
			System.out.println("delete where student_id = 45");
			PreparedStatement deleteQuery = myDBConnection.prepareStatement("delete from courses where course_id = ?");
			deleteQuery.setInt(1, 45);
			int deleteResult = deleteQuery.executeUpdate();
            System.out.println(deleteResult);
			System.out.println();
			
			System.out.println("Select Output");
            PreparedStatement selectQuery4 = myDBConnection.prepareStatement("select * from courses");
			ResultSet rs4 = selectQuery.executeQuery();
            while(rs4.next()){
                System.out.println(rs4.getInt(1) + " " + rs4.getString(2) + " " +rs4.getInt(3));
            }
			System.out.println();
        }
        catch(SQLException e){
            e.printStackTrace();
        }
	}
	public static void main(String[] args){
		DBConnection DBConnTest = new DBConnection(); 
	}
}