<%@ page import = "java.io.*,java.util.*,java.sql.*"%>
                <%
                String hostName = "ec2-54-163-240-54.compute-1.amazonaws.com";
                String dbName = "d89l9begjikklj";
                String userName = "isscllglmxgeln";
                String password = "334f696049572d4bc9c3b6b78c3410301e24dd3b5fd2b96dc15bf4c1c6fed113";
                
                Connection conn = null;

                try {
                    Class.forName("org.postgresql.Driver");
                    String url = "jdbc:postgresql://" + hostName + "/" + dbName + "?user=" + userName + "&password=" + password + "&ssl=true&sslfactory=org.postgresql.ssl.NonValidatingFactory";
                    conn = DriverManager.getConnection(url);
                } catch(Exception e) {out.println(e.getMessage());}

                                if(request.getParameter("username") != null) {
                                    String username = request.getParameter("username");
                                    String passWord = request.getParameter("password");
                                    String opponent = request.getParameter("opponent");
                                    String sql = "select * from chess_signup where username = '" + username + "' and password = '" + passWord + "';";
                                    
                                    Statement st = conn.createStatement();
                                    ResultSet rs = st.executeQuery(sql);
                                    if(rs.next()) {
                                        Statement st2 = conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
                                        sql = "select * from chess_signedin where username = '" + username + "' and signedin = 1;";
                                        ResultSet rs2 = st2.executeQuery(sql);
                                        if(rs2.next()) {
                                            sql = "select max(id)+1 as nextid from chess_game;";
                                            ResultSet rs3 = st2.executeQuery(sql);
                                            int nextid = -1;
                                            if(rs3.next()) {
                                                nextid = rs3.getInt("nextid");
                                            } else {
                                                nextid = 1;
                                            }
                                            sql = "insert into chess_game (id, player, timestamp, color, opponent) values (" + nextid + ", '" + username + "', clock_timestamp(), 'white', '" + opponent + "');";
                                            st2.execute(sql);
                                            out.print("{" + nextid);
                                        }
                                    }
                                }
                if(conn != null) {
                    try {
                        conn.close();
                    } catch(Exception e) {}
                }
                %>