<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0"
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:template match="/">
    <html>
      <body>
        <table border="1">
          <tr>
            <th>Name</th>
            <th>Phone1</th>
            <th>Phone2</th>
            <th>Phone3</th>
            <th>address (street, building no, region, city, country)</th>
            <th>address (street, building no, region, city, country)</th>
            <th>email</th>
          </tr>
          <xsl:for-each select="Employees/Employee">
            <tr>
              <td><xsl:value-of select="name"/></td>
              <xsl:for-each select="phones">
              <td><xsl:value-of select="phone[1]"/>, <xsl:value-of select="phone[1]/@type"/></td>
              <td><xsl:value-of select="phone[2]"/>, <xsl:value-of select="phone[2]/@type"/></td>
              <td><xsl:value-of select="phone[3]"/>, <xsl:value-of select="phone[3]/@type"/></td>
              </xsl:for-each>
              <xsl:for-each select="addresses">
                <td><xsl:value-of select="address[1]"/></td>
                <td><xsl:value-of select="address[2]"/></td>
              </xsl:for-each>
              <td><xsl:value-of select="email"/></td>
            </tr>
          </xsl:for-each>
        </table>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>