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
                                    String sql = "select * from chess_signup where username = '" + username + "' and password = '" + passWord + "';";
                                    
                                    Statement st = conn.createStatement();
                                    ResultSet rs = st.executeQuery(sql);
                                    if(rs.next()) {
                                        Statement st2 = conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
                                        sql = "select * from chess_signedin where username = '" + username + "' and signedin = 1;";
                                        ResultSet rs2 = st2.executeQuery(sql);
                                        if(rs2.next()) {
                                            sql = "select id, player from chess_game where accept is null and opponent = '" + username + "' order by id desc;";
                                            ResultSet rs3 = st2.executeQuery(sql);
                                            if(rs3.next()) {
                                                String opp = rs3.getString("player");
                                                String tgid = rs3.getString("id");
                                                sql = "select id from chess_signup where username = '" + opp + "';";
                                                ResultSet rs4 = st2.executeQuery(sql);
                                                if(rs4.next()) {
                                                    out.print("{" + rs4.getInt("id"));
                                                    out.print("{" + tgid + "{" + opp);
                                                }
                                            } else {
                                                out.print("{notGameRequest{p");
                                            }
                                        } else {
                                            out.print("{abc!@{#");
                                        }
                                    }
                                }
                if(conn != null) {
                    try {
                        conn.close();
                    } catch(Exception e) {}
                }
                %>