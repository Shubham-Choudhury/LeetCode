-- Link: https://leetcode.com/problems/patients-with-a-condition/?envType=study-plan&id=sql-i

select patient_id, patient_name, conditions from Patients where conditions like 'DIAB1%' or conditions like '% DIAB1%'