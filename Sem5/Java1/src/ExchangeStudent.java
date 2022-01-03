/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author 19pw06
 */
public class ExchangeStudent extends Student {
    private String collegeName;
    private Date startDate;
    private Date endDate;

    public ExchangeStudent(String collegeName, Date startDate, Date endDate, String name, String rollNo, Date dateOfBirth, Date dateOfJoining) {
        super(name, rollNo, dateOfBirth, dateOfJoining);
        this.collegeName = collegeName;
        this.startDate = startDate;
        this.endDate = endDate;
    }
    
    public String getCollegeName() {
        return collegeName;
    }

    public Date getStartDate() {
        return startDate;
    }

    public Date getEndDate() {
        return endDate;
    }

    public void setCollegeName(String collegeName) {
        this.collegeName = collegeName;
    }

    public void setStartDate(Date startDate) {
        this.startDate = startDate;
    }

    public void setEndDate(Date endDate) {
        this.endDate = endDate;
    }

    
    
    
}
