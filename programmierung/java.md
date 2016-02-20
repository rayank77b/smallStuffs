# Java Samples/Tutorials

At the time of writing the filename and version was jdk-7u17-linux-x64.tar.gz

 Untar the Archive
 ```shell
tar -xzvf /root/jdk-7u17-linux-x64.tar.gz
mv jdk1.7.0_17 /opt
cd /opt/jdk1.7.0_17
```

This step registers the downloaded version of Java as an alternative, and switches it to be used as the default:

```shell
update-alternatives --install /usr/bin/java java /opt/jdk1.7.0_17/bin/java 1
update-alternatives --install /usr/bin/javac javac /opt/jdk1.7.0_17/bin/javac 1
update-alternatives --install /usr/lib/mozilla/plugins/libjavaplugin.so mozilla-javaplugin.so /opt/jdk1.7.0_17/jre/lib/amd64/libnpjp2.so 1
update-alternatives --set java /opt/jdk1.7.0_17/bin/java
update-alternatives --set javac /opt/jdk1.7.0_17/bin/javac
update-alternatives --set mozilla-javaplugin.so /opt/jdk1.7.0_17/jre/lib/amd64/libnpjp2.so
```

Test

To check the version of Java you are now running
```shell
java -version
```


java.sql.*

connecting to Driver Interface
```java
try {
    class.forName("com.mysql.jdbc.Driver").newInstance();
} catch ( Exception e) { ... }

Connection cn = DriverManager.getConnection("jdbc:mysql://localhost/test?user=bla&password=bla");

SQLException ex;
ex.getMessage().ex_getSQLState()
ex.getErrorCode()

Statement st = cn.createStatement();
ResultSet rs = st.executeQuery("SELECT ...");

if( st.execute("SELECT ..."))
rs = st.getResultSet();

rs.close(); st.close();
```

derby -> apache
```java
System.setProperty("derby.system.home", "dbname.db");
Connection conn = DriverManager.getConnection("jdbc:derby:test_db;create=true");

try {
    Statement s = conn.createStatement();
    s.execute("CREATE TABLE data (id INT, text VARCHAR(100), PRIMARY KEY (id))");
    s.execute("INSERT INTO data VALUES (1, 'Hallo')");
    s.execute("INSERT INTO data VALUES (2, 'Blub')");
    ResultSet rs = s.exeucteQuery("SELECT text FROM data WHERE id=1");
    while (rs.next()) {
        String text = rs.getString("text");
        System.out.println(text);
    }
} finally {
    conn.close();
}
```

read from input:

```java
BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
String name = br.readLine();
int age = new Integer( br.readLine() ).intValue();
```
