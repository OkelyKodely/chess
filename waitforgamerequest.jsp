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
                                            Statement st3 = conn.createStatement();
                                            if(opponent == null)
                                                opponent = "";
                                            if(opponent.equals("")) {
                                                sql = "select accept, id from chess_game where player = '" + username + "' and ((accept = 3 or accept = 2) and accept is not null) order by id desc;";
                                                ResultSet r = st3.executeQuery(sql);
                                                if(r.next()) {
                                                    int accept = r.getInt("accept");
                                                    if(accept == 3)
                                                        sql = "update chess_game set accept = 0 where id = " + r.getInt("id");
                                                    else if(accept == 2)
                                                        sql = "update chess_game set accept = 0 where id = " + r.getInt("id");
                                                    if(accept == 3 || accept == 2)
                                                        st3.execute(sql);
                                                    if(accept == 3) {
                                                        out.print("{denied{"+r.getInt("id"));
                                                    } else if(accept == 2) {
                                                        out.print("{denied{"+r.getInt("id"));
                                                    }
                                                }
                                            } else {
                                                sql = "select accept, id from chess_game where player = '" + username + "' and opponent = '" + opponent + "' and ((accept = 3 or accept = 2) and accept is not null) order by id desc;";
                                                ResultSet rs4 = st3.executeQuery(sql);
                                                int accept = -1;
                                                if(rs4.next()) {
                                                    accept = rs4.getInt("accept");
                                                    if(accept == 3) {
                                                        out.print("{accepted{"+rs4.getInt("id"));
                                                    } else if(accept == 2) {
                                                        out.print("{denied{"+rs4.getInt("id"));
                                                    }
                                                } else {
                                                    out.print("{standby");
                                                }
                                            }
                                        }
                                    }
                                }
                if(conn != null) {
                    try {
                        conn.close();
                    } catch(Exception e) {}
                }
                %>