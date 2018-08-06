<%@ page import = "java.io.*,java.util.*,java.sql.*"%>
<html>
    <head>
        <title>Sign In</title>
        <link rel="stylesheet" type="text/css"href="conf.css">
        <link href="https://getbootstrap.com/docs/4.1/dist/css/bootstrap.min.css" rel="stylesheet">
        <style>
            a {
                text-decoration: underline;
                text-decoration-color: red;
            }
            a:hover {
                color: hotpink;
            }
            textarea {
                width: 260px;
                height: 400px;
                background-color: #3CBC8D;
            }
            * {
                font-size: 13px;
            }
        </style>
    </head>
    <body bgcolor="black">
    <center>
        <table width="550" bgcolor="white">
            <tr>
                <td align="left">
                    <a href="/"><img src="logo.png"></a>
        <H3>Sign In</H3>
        <HR align="left" style="width:550px"/>
        <table width="550">
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
                                        Statement st2 = conn.createStatement();
                                        sql = "select * from chess_signedin where username = '" + username + "';";
                                        ResultSet rs2 = st2.executeQuery(sql);
                                        if(rs2.next()) {
                                            sql = "update chess_signedin set signedin = 1, lastsignin = clock_timestamp() where username = '" + username + "';";
                                            st2.execute(sql);
                                        } else {
                                            sql = "insert into chess_signedin (username, signedin, lastsignin) values ('" + username + "', 1, clock_timestamp());";
                                            st2.execute(sql);
                                        }
                                    %>
                                    <tr><td colspan="2">Signed in.</td></tr>
                                    <%
                                    }
                                }
                        %>
                        <form method="post" action="signin.jsp">
                        <tr>
                            <td>
                                Username:
                            </td>
                            <td>
                                <input type="text" name="username">
                            </td>
                        </tr>
                        <tr>
                            <td>
                                Password:
                            </td>
                            <td>
                                <input type="password" name="password">
                                <br>
                                <input type="submit" value="Sign in.">
                            </td>
                        </tr>
                        </form>
                        <%
                if(conn != null) {
                    try {
                        conn.close();
                    } catch(Exception e) {}
                }
                %>
        </table>
                </td>
            </tr>
        </table>
    </center>
    </body>
</html>